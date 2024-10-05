// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/GameWorld/SG_Grid.h"
#include "Core/Grid.h"
#include "DrawDebugHelpers.h"

DEFINE_LOG_CATEGORY_STATIC(LogWorldGrid, All, All);

ASG_Grid::ASG_Grid() : Super()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASG_Grid::SetModel(const TSharedPtr<SnakeGame::Grid>& Grid, int32 InCellSize)
{
	if (!Grid.IsValid())
	{
		UE_LOG(LogWorldGrid, Error, TEXT("Grid is null, game aborted!"))
		return;
	}
	
	GridDimension = Grid.Get()->getDimension();
	CellSize = InCellSize;
	WorldWidth = GridDimension.width * CellSize;
	WorldHeight = GridDimension.height * CellSize;
}


void ASG_Grid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	DrawGrid();
}

void ASG_Grid::DrawGrid()
{
	for (int32 i = 0; i < GridDimension.height + 1; ++i)
	{
		const FVector StartLocation = GetActorLocation() + GetActorForwardVector() * CellSize * i;
		const FVector EndLocation = StartLocation + GetActorRightVector() * WorldWidth;
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.0f, 1.f);
	}

	for (int32 i = 0; i < GridDimension.width + 1; ++i)
	{
		const FVector StartLocation = GetActorLocation() + GetActorRightVector() * CellSize * i;
		const FVector EndLocation = StartLocation + GetActorForwardVector() * WorldHeight;
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.0f, 1.f);
	}
}

