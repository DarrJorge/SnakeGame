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

	for (auto* LinkActor : SnakeLinks)
	{
		LinkActor->Destroy();
	}
	SnakeLinks.Empty();

	if (!Snake.IsValid() || !GetWorld()) return;

	const auto& Links = Snake.Pin()->links();

	uint32 i = 0;
	for (const auto& Link : Links)
	{
		const FTransform Transform = FTransform(SG_Utils::LinkPositionToVector(Link, CellSize, Dimension));
		auto* LinkActor = GetWorld()->SpawnActorDeferred<ASG_SnakeLink>(i == 0 ? SnakeHeadClass : SnakeBodyClass, Transform);
		LinkActor->UpdateScale(CellSize);
		LinkActor->FinishSpawning(Transform);
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

	for (auto* LinkActor : SnakeLinks)
	{
		LinkActor->SetActorLocation(SG_Utils::LinkPositionToVector(LinkPtr->GetValue(), CellSize, Dimension));
		LinkPtr = LinkPtr->GetNextNode();
	}

	// add links if snake ate food
	while (LinkPtr)
	{
		const FTransform Transform = FTransform(SG_Utils::LinkPositionToVector(LinkPtr->GetValue(), CellSize, Dimension));
		auto* LinkActor = GetWorld()->SpawnActorDeferred<ASG_SnakeLink>(SnakeBodyClass, Transform);
		LinkActor->UpdateScale(CellSize);
		LinkActor->UpdateColor(SnakeLinkColor);
		LinkActor->FinishSpawning(Transform);
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
	for (auto* LinkActor : SnakeLinks)
	{
		LinkActor->Explode();
	}
}
