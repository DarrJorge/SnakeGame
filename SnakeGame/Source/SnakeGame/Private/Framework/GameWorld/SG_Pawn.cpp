// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/GameWorld/SG_Pawn.h"
#include "Camera/CameraComponent.h"

namespace
{
	double HalfFOVTan(double FOVDegrees)
	{
		return FMath::Tan(FMath::DegreesToRadians(FOVDegrees * 0.5));
	}

	double CalculateVerticalFOV(double HorizontalFOVDegrees, double ViewportAspectHW)
	{
		return FMath::RadiansToDegrees(2.0 * FMath::Atan(FMath::Tan(FMath::DegreesToRadians(HorizontalFOVDegrees) * 0.5) * ViewportAspectHW));
	}

	constexpr double GridMargin = 2.0;
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
	Viewport->ViewportResizedEvent.Remove(ResizeHandle);
	ResizeHandle = Viewport->ViewportResizedEvent.AddUObject(this, &ASG_Pawn::OnViewportResized);

#if WITH_EDITOR
	OnViewportResized(Viewport, 0);
#endif
}

void ASG_Pawn::OnViewportResized(FViewport* Viewport, uint32 Value)
{
	if (!Viewport || Viewport->GetSizeXY().Y == 0 || Dimension.height == 0) return;
	
	double LocationZ = 0.0;
	const double WorldWidth = Dimension.width * CellSize;
	const double WorldHeight = Dimension.height * CellSize;
	
	const double ViewportAspectRatio = static_cast<double>(Viewport->GetSizeXY().X) / Viewport->GetSizeXY().Y;
	const double GridAspect = static_cast<double>(Dimension.width) / Dimension.height;
	
	if (ViewportAspectRatio <= GridAspect)
	{
		const double MarginWidth = (Dimension.width + GridMargin) * CellSize;
		LocationZ = MarginWidth / HalfFOVTan(Camera->FieldOfView);
	}
	else
	{
		const double MarginHeight = (Dimension.height + GridMargin) * CellSize;
		const double VerticalFOV = CalculateVerticalFOV(Camera->FieldOfView, 1.0 / ViewportAspectRatio);
		LocationZ = MarginHeight / HalfFOVTan(VerticalFOV);
	}
	
	const FVector NewPawnLocation = GridOrigin.GetLocation() + 0.5 * FVector(WorldHeight, WorldWidth, LocationZ);
	SetActorLocation(NewPawnLocation);
}

