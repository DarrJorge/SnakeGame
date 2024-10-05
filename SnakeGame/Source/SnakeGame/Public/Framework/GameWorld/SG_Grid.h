// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Game.h"
#include "GameFramework/Actor.h"
#include "SG_Grid.generated.h"

namespace SnakeGame
{
	class Grid;
}

UCLASS()
class SNAKEGAME_API ASG_Grid : public AActor
{
	GENERATED_BODY()
	
public:	
	ASG_Grid();
	
	void SetModel(const TSharedPtr<SnakeGame::Grid>& Grid, int32 InCellSize);
	
	virtual void Tick(float DeltaTime) override;

private:
	SnakeGame::Dimension GridDimension;
	int32 CellSize;
	int32 WorldWidth;
	int32 WorldHeight;

	void DrawGrid();
};
