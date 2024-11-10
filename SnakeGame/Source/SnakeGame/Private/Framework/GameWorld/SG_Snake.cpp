// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/GameWorld/SG_Snake.h"
#include "Framework/GameWorld/SG_SnakeLink.h"

using namespace SnakeGame;

namespace
{
	FVector LinkPositionToVector(const Position& Position, uint32 CellSize, const Dimension& Dimension)
	{
		const double PositionX = (Dimension.height - 1 - Position.y) * CellSize;
		return FVector(PositionX, Position.x * CellSize, 0.0) + FVector(CellSize * 0.5);
	}
}

ASG_Snake::ASG_Snake() : Super()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASG_Snake::BeginPlay()
{
	Super::BeginPlay();

	if (!Snake.IsValid() || !GetWorld()) return;

	const auto& Links = Snake.Pin()->links();

	uint32 i = 0;
	for (const auto& Link : Links)
	{
		const FTransform Transform = FTransform(LinkPositionToVector(Link, CellSize, Dimension));
		auto* LinkActor = GetWorld()->SpawnActorDeferred<ASG_SnakeLink>(i == 0 ? SnakeHeadClass : SnakeBodyClass, Transform);
		LinkActor->UpdateScale(CellSize);
		LinkActor->FinishSpawning(Transform);
		SnakeLinks.Add(LinkActor);
		++i;
	}
}

void ASG_Snake::SetModel(const TSharedPtr<SnakeGame::Snake>& InSnake, uint32 InCellSize, const SnakeGame::Dimension& InDimension)
{
	Snake = InSnake;
	CellSize = InCellSize;
	Dimension = InDimension;
}

void ASG_Snake::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Snake.IsValid()) return;
	const auto& Links = Snake.Pin()->links();
	auto* LinkPtr = Links.GetHead();

	for (auto* LinkActor : SnakeLinks)
	{
		LinkActor->SetActorLocation(LinkPositionToVector(LinkPtr->GetValue(), CellSize, Dimension));
		LinkPtr = LinkPtr->GetNextNode();
	}
}

void ASG_Snake::UpdateColors(const FSnakeColors& Colors)
{
	for (int32 i = 0; i < SnakeLinks.Num(); ++i)
	{
		SnakeLinks[i]->UpdateColors(i == 0 ? Colors.SnakeHeadColor : Colors.SnakeLinkColor);
	}
}
