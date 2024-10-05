// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/SC_GameMode.h"
#include "Framework/GameWorld/SG_Grid.h"

void ASC_GameMode::StartPlay()
{
	Super::StartPlay();

	check(GetWorld());

	SnakeGame::Settings GridSizeLocal{GridSize.X, GridSize.Y};
	CoreGame = MakeUnique<SnakeGame::Game>(GridSizeLocal);

	const FTransform GridOrigin = FTransform::Identity;
	GridVisual = GetWorld()->SpawnActorDeferred<ASG_Grid>(GridVisualClass, GridOrigin);
	if (GridVisual)
	{
		GridVisual->SetModel(CoreGame->getGrid(), CellSize);
		GridVisual->FinishSpawning(GridOrigin);
	}
}
