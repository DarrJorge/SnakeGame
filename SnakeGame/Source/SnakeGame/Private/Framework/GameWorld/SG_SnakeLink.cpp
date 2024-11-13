// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/GameWorld/SG_SnakeLink.h"
#include "Components/StaticMeshComponent.h"
#include "Framework/GameWorld/SG_Utils.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"


ASG_SnakeLink::ASG_SnakeLink() : Super()
{
	PrimaryActorTick.bCanEverTick = false;

	Origin = CreateDefaultSubobject<USceneComponent>("Origin");
	SetRootComponent(Origin);

	LinkMesh = CreateDefaultSubobject<UStaticMeshComponent>("LinkMesh");
	LinkMesh->SetupAttachment(Origin);
}

void ASG_SnakeLink::UpdateScale(uint32 CellSize) const
{
	SnakeGame::SG_Utils::ScaleMesh(LinkMesh, FVector(CellSize));
}

void ASG_SnakeLink::UpdateColor(const FLinearColor& Color)
{
	LinkColor = Color;
	if (auto* LinkMaterial = LinkMesh->CreateAndSetMaterialInstanceDynamic(0))
	{
		LinkMaterial->SetVectorParameterValue("Color", Color);
	}
}

void ASG_SnakeLink::Explode()
{
	if (auto* NS = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ExplosionEffect, GetActorLocation()))
	{
		NS->SetVariableLinearColor("SnakeColor", LinkColor);
	}
	SetActorHiddenInGame(true);
}
