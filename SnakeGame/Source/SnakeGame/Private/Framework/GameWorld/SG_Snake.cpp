// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/GameWorld/SG_Snake.h"
#include "Framework/GameWorld/SG_SnakeLink.h"
#include "Framework/GameWorld/SG_Utils.h"

using namespace SnakeGame;

ASG_Snake::ASG_Snake() : Super()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASG_Snake::SetModel(const TSharedPtr<SnakeGame::Snake>& InSnake, uint32 InCellSize, const SnakeGame::Dimension& InDimension)
{
	Snake = InSnake;
	CellSize = InCellSize;
	Dimension = InDimension;

	for (auto LinkActor : SnakeLinks)
	{
		Push(LinkActor);
	}
	SnakeLinks.Empty();

	if (!Snake.IsValid() || !GetWorld()) return;

	const auto& Links = Snake.Pin()->links();

	uint32 i = 0;
	for (const auto& Link : Links)
	{
		const FTransform Transform = FTransform(SG_Utils::LinkPositionToVector(Link, CellSize, Dimension));
		auto* LinkActor = Pop(Transform, SnakeBodyClass);
		LinkActor->UpdateScale(CellSize);
		SnakeLinks.Add(LinkActor);
		++i;
	}
}

void ASG_Snake::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Snake.IsValid()) return;
	const auto& Links = Snake.Pin()->links();
	auto* LinkPtr = Links.GetHead();

	for (auto LinkActor : SnakeLinks)
	{
		LinkActor->SetActorLocation(SG_Utils::LinkPositionToVector(LinkPtr->GetValue(), CellSize, Dimension));
		LinkPtr = LinkPtr->GetNextNode();
	}

	// add links if snake ate food
	while (LinkPtr)
	{
		const FTransform Transform = FTransform(SG_Utils::LinkPositionToVector(LinkPtr->GetValue(), CellSize, Dimension));
		auto* LinkActor = Pop(Transform, SnakeBodyClass);
		LinkActor->UpdateScale(CellSize);
		LinkActor->UpdateColor(SnakeLinkColor);
		SnakeLinks.Add(LinkActor);
		LinkPtr = LinkPtr->GetNextNode();
	}
}

void ASG_Snake::UpdateColors(const FSnakeColors& Colors)
{
	SnakeLinkColor = Colors.SnakeLinkColor;
	for (int32 i = 0; i < SnakeLinks.Num(); ++i)
	{
		SnakeLinks[i]->UpdateColor(i == 0 ? Colors.SnakeHeadColor : Colors.SnakeLinkColor);
	}
}

void ASG_Snake::Explode()
{
	for (auto LinkActor : SnakeLinks)
	{
		LinkActor->Explode();
	}
}

ASG_SnakeLink* ASG_Snake::Pop(const FTransform& Transform, const TSubclassOf<AActor>& SnakeLinkClass)
{
	auto* LinkActor = SnakeLinksPool.IsEmpty() ?
		GetWorld()->SpawnActor<ASG_SnakeLink>(SnakeLinkClass, Transform) : SnakeLinksPool.Pop().Get();
		
	check(LinkActor);
	LinkActor->SetActorHiddenInGame(false);
	return LinkActor;
}

void ASG_Snake::Push(ASG_SnakeLink* Actor)
{
	if (!Actor) return;
	Actor->SetActorHiddenInGame(false);
	Actor->UpdateColor(FLinearColor::Black);
	Actor->SetActorLocation(FVector(0.0, 100.0 + SnakeLinksPool.Num() * 30.0, 0.0));
	SnakeLinksPool.Add(Actor);
}
