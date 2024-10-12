// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/GameWorld/SG_Grid.h"
#include "Core/Grid.h"
#include "DrawDebugHelpers.h"
#include "Components/LineBatchComponent.h"
#include "Components/StaticMeshComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogWorldGrid, All, All);

ASG_Grid::ASG_Grid() : Super()
{
	PrimaryActorTick.bCanEverTick = false;

	Origin = CreateDefaultSubobject<USceneComponent>("Origin");
	check(Origin);
	SetRootComponent(Origin);

	GridMesh = CreateDefaultSubobject<UStaticMeshComponent>("GridMesh");
	check(GridMesh);
	GridMesh->SetupAttachment(Origin);
}

void ASG_Grid::SetModel(const TSharedPtr<SnakeGame::Grid>& Grid, uint32 InCellSize)
{
	if (!Grid)
	{
		UE_LOG(LogWorldGrid, Error, TEXT("Grid is null, game aborted!"))
		return;
	}
	
	GridDimension = Grid->getDimension();
	CellSize = InCellSize;
	WorldWidth = GridDimension.width * CellSize;
	WorldHeight = GridDimension.height * CellSize;

	// scale mesh
	check(GridMesh->GetStaticMesh());
	const FBox Box = GridMesh->GetStaticMesh()->GetBoundingBox();
	const auto Size = Box.GetSize();

	check(Size.X && Size.Y);
	GridMesh->SetRelativeScale3D(FVector(WorldHeight / Size.X, WorldWidth / Size.Y, 1.0));
	GridMesh->SetRelativeLocation(0.5 * FVector(WorldHeight, WorldWidth, -Size.Z));

	// setup material for grid
	GridMaterial = GridMesh->CreateAndSetMaterialInstanceDynamic(0);
	if (GridMaterial)
	{
		FVector Value = FVector(GridDimension.height, GridDimension.width, 0.0);
		GridMaterial->SetVectorParameterValue("Division", Value);
	}
}

void ASG_Grid::UpdateColors(const FSnakeColors& Colors)
{
	if (GridMaterial)
	{
		GridMaterial->SetVectorParameterValue("BackgroundColor", Colors.GridBackgroundColor);
		GridMaterial->SetVectorParameterValue("WallColor", Colors.GridWallColor);
		GridMaterial->SetVectorParameterValue("LineColor", Colors.GridLineColor);
	}
}

void ASG_Grid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//DrawGrid();
}

void ASG_Grid::DrawGrid()
{
	if (!GetWorld() || !GetWorld()->LineBatcher) return;
	
	for (uint32 i = 0; i < GridDimension.height + 1; ++i)
	{
		const FVector StartLocation = GetActorLocation() + GetActorForwardVector() * CellSize * i;
		const FVector EndLocation = StartLocation + GetActorRightVector() * WorldWidth;
		//DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.0f, 0,2.f);
		GetWorld()->LineBatcher->DrawLine(StartLocation, EndLocation, FLinearColor::Red, 1, 1.f);
	}

	for (uint32 i = 0; i < GridDimension.width + 1; ++i)
	{
		const FVector StartLocation = GetActorLocation() + GetActorRightVector() * CellSize * i;
		const FVector EndLocation = StartLocation + GetActorForwardVector() * WorldHeight;
		//DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.0f, 0,2.f);
		GetWorld()->LineBatcher->DrawLine(StartLocation, EndLocation, FLinearColor::Red, 1, 1.f);
	}
}

