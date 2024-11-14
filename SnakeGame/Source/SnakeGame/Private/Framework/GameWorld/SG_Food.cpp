// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/GameWorld/SG_Food.h"
#include "Components/StaticMeshComponent.h"
#include "Framework/GameWorld/SG_Utils.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

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

	SetActorHiddenInGame(false);
	
	SG_Utils::ScaleMesh(FoodMesh, FVector(CellSize));
}

void ASG_Food::UpdateColor(const FLinearColor& Color)
{
	FoodColor = Color;
	
	if (auto* LinkMaterial = FoodMesh->CreateAndSetMaterialInstanceDynamic(0))
	{
		LinkMaterial->SetVectorParameterValue("Color", Color);
	}
}

void ASG_Food::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetFoodWorldLocation());
}

void ASG_Food::Explode()
{
	if (auto* NS = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ExplosionEffect, GetFoodWorldLocation()))
	{
		NS->SetVariableLinearColor("SnakeColor", FoodColor);
	}
}

void ASG_Food::Hide()
{
	SetActorHiddenInGame(true);
}

FVector ASG_Food::GetFoodWorldLocation() const
{
	if (!Food.IsValid()) return FVector::ZeroVector;
	return SG_Utils::LinkPositionToVector(Food.Pin()->getPosition(), CellSize, Dimension);
}
