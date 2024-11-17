// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/GameWorld/SG_Trap.h"
#include "Components/StaticMeshComponent.h"
#include "Framework/GameWorld/SG_Utils.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

using namespace SnakeGame;

ASG_Trap::ASG_Trap() : Super()
{
	PrimaryActorTick.bCanEverTick = true;

	Origin = CreateDefaultSubobject<USceneComponent>("Origin");
	SetRootComponent(Origin);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("VisualMesh");
	Mesh->SetupAttachment(Origin);
}


void ASG_Trap::SetModel(const TSharedPtr<SnakeGame::Trap>& InTrap, uint32 InCellSize, const SnakeGame::Dimension& Dims)
{
	Trap = InTrap;
	CellSize = InCellSize;
	Dimension = Dims;

	SetActorHiddenInGame(false);
	
	SG_Utils::ScaleMesh(Mesh, FVector(CellSize));
}

void ASG_Trap::UpdateColor(const FLinearColor& Color)
{
	TrapColor = Color;
	
	if (auto* LinkMaterial = Mesh->CreateAndSetMaterialInstanceDynamic(0))
	{
		LinkMaterial->SetVectorParameterValue("Color", Color);
	}
}

void ASG_Trap::Explode()
{
	if (auto* NS = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ExplosionEffect, GetTrapWorldLocation()))
	{
		NS->SetVariableLinearColor("SnakeColor", TrapColor);
	}
}

void ASG_Trap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetTrapWorldLocation());
}

void ASG_Trap::Hide()
{
	SetActorHiddenInGame(true);
}

FVector ASG_Trap::GetTrapWorldLocation() const
{
	if (!Trap.IsValid()) return FVector::ZeroVector;
	return SG_Utils::LinkPositionToVector(Trap.Pin()->getPosition(), CellSize, Dimension);
}
