// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/GameWorld/SG_Food.h"
#include "Components/StaticMeshComponent.h"
#include "Framework/GameWorld/SG_Utils.h"

using namespace SnakeGame;

ASG_Food::ASG_Food():Super()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Origin = CreateDefaultSubobject<USceneComponent>("Origin");
	SetRootComponent(Origin);

	FoodMesh = CreateDefaultSubobject<UStaticMeshComponent>("FoodMesh");
	FoodMesh->SetupAttachment(Origin);
}

void ASG_Food::SetModel(const TSharedPtr<SnakeGame::Food>& InFood, uint32 InCellSize, const SnakeGame::Dimension& Dims)
{
	Food = InFood;
	CellSize = InCellSize;
	Dimension = Dims;
	
	SG_Utils::ScaleMesh(FoodMesh, FVector(CellSize));
}

void ASG_Food::UpdateColor(const FLinearColor& Color)
{
	if (auto* LinkMaterial = FoodMesh->CreateAndSetMaterialInstanceDynamic(0))
	{
		LinkMaterial->SetVectorParameterValue("Color", Color);
	}
}

void ASG_Food::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Food.IsValid())
	{
		SetActorLocation(SG_Utils::LinkPositionToVector(Food.Pin()->getPosition(), CellSize, Dimension));
	}
}
