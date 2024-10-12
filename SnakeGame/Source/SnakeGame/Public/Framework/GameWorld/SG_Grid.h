// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Game.h"
#include "GameFramework/Actor.h"
#include "Framework/GameWorld/SG_WorldTypes.h"
#include "SG_Grid.generated.h"

namespace SnakeGame
{
	class Grid;
}

class UStaticMeshComponent;

UCLASS()
class SNAKEGAME_API ASG_Grid : public AActor
{
	GENERATED_BODY()
	
public:	
	ASG_Grid();

	/**
	 * Set core model to be observed by the grid world actor
	 * @param Grid model object
	 * @param InCellSize world size of the cell 
	 */
	void SetModel(const TSharedPtr<SnakeGame::Grid>& Grid, uint32 InCellSize);
	void UpdateColors(const FSnakeColors& Colors);
	
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Origin;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* GridMesh;

private:
	UPROPERTY()
	UMaterialInstanceDynamic* GridMaterial;
	
	SnakeGame::Dimension GridDimension;
	uint32 CellSize;
	uint32 WorldWidth;
	uint32 WorldHeight;

	void DrawGrid();
};
