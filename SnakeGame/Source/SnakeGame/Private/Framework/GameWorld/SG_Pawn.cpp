// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/GameWorld/SG_Pawn.h"
#include "Camera/CameraComponent.h"

namespace
{
	float HalfFOVTan(float FOVDegrees)
	{
		return FMath::Tan(FMath::DegreesToRadians(FOVDegrees * 0.5f));
	}

	float CalculateVerticalFOV(float HorizontalFOVDegrees, float ViewportAspectHW)
	{
		return FMath::RadiansToDegrees(2.0f * FMath::Atan(FMath::Tan(FMath::DegreesToRadians(HorizontalFOVDegrees) * 0.5f) * ViewportAspectHW));
	}
}

ASG_Pawn::ASG_Pawn() : Super()
{
	PrimaryActorTick.bCanEverTick = false;

	CameraBoom = CreateDefaultSubobject<USceneComponent>("Origin");
	SetRootComponent(CameraBoom);
	
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(CameraBoom);
}

void ASG_Pawn::UpdateLocation(const SnakeGame::Dimension& InDimension, int32 InCellSize, const FTransform& InGridOrigin)
{
	Dimension = InDimension;
	CellSize = InCellSize;
	GridOrigin = InGridOrigin;

	check(GEngine);
	check(GEngine->GameViewport);
	check(GEngine->GameViewport->Viewport);
	
	FViewport* Viewport = GEngine->GameViewport->Viewport;
	Viewport->ViewportResizedEvent.AddUObject(this, &ASG_Pawn::OnViewportResized);

#if WITH_EDITOR
	OnViewportResized(Viewport, 0);
#endif
}

void ASG_Pawn::OnViewportResized(FViewport* Viewport, uint32 Value)
{
	if (!Viewport || Viewport->GetSizeXY().Y == 0 || Dimension.height == 0) return;
	
	float LocationZ;
	const float WorldWidth = Dimension.width * CellSize;
	const float WorldHeight = Dimension.height * CellSize;
	
	const float ViewportAspectRatio = static_cast<float>(Viewport->GetSizeXY().X) / Viewport->GetSizeXY().Y;
	const float GridAspect = static_cast<float>(Dimension.width) / Dimension.height;
	
	if (ViewportAspectRatio <= GridAspect)
	{
		LocationZ = WorldWidth / HalfFOVTan(Camera->FieldOfView);
	}
	else
	{
		const float VerticalFOV = CalculateVerticalFOV(Camera->FieldOfView, 1.f / ViewportAspectRatio);
		LocationZ = WorldHeight / HalfFOVTan(VerticalFOV);
	}
	
	const FVector NewPawnLocation = GridOrigin.GetLocation() + 0.5f * FVector(WorldHeight, WorldWidth, LocationZ);
	SetActorLocation(NewPawnLocation);
}

