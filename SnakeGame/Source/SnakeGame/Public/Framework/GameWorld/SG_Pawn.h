// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Types.h"
#include "GameFramework/Pawn.h"
#include "SG_Pawn.generated.h"

class UCameraComponent;

UCLASS()
class SNAKEGAME_API ASG_Pawn : public APawn
{
	GENERATED_BODY()

public:
	ASG_Pawn();

	void UpdateLocation(const SnakeGame::Dimension& InDimension, int32 InCellSize, const FTransform& InGridOrigin);

protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

private:
	SnakeGame::Dimension Dimension;
	int32 CellSize;
	FTransform GridOrigin;
	FDelegateHandle ResizeHandle;
	
	void OnViewportResized(FViewport* Viewport, uint32 Value);
};
