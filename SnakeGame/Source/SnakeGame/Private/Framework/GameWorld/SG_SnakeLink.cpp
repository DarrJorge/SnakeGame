// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/GameWorld/SG_SnakeLink.h"
#include "Components/StaticMeshComponent.h"


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
	// scale mesh
	check(LinkMesh->GetStaticMesh());
	const FBox Box = LinkMesh->GetStaticMesh()->GetBoundingBox();
	const auto Size = Box.GetSize();

	check(Size.X);
	check(Size.Y);
	check(Size.Z);
	LinkMesh->SetRelativeScale3D(FVector(CellSize / Size.X, CellSize / Size.Y, CellSize / Size.Z));
}

void ASG_SnakeLink::UpdateColors(const FLinearColor& Color) const
{
	if (auto* LinkMaterial = LinkMesh->CreateAndSetMaterialInstanceDynamic(0))
	{
		LinkMaterial->SetVectorParameterValue("Color", Color);
	}
}
