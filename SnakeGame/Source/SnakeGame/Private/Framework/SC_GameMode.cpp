// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/SC_GameMode.h"
#include "Core/Grid.h"
#include "Framework/GameWorld/SG_Grid.h"
#include "Framework/GameWorld/SG_Pawn.h"

void ASC_GameMode::StartPlay()
{
	Super::StartPlay();

	check(GetWorld());

	// init core game
	SnakeGame::Settings GridSizeLocal{GridSize.X, GridSize.Y};
	CoreGame = MakeUnique<SnakeGame::Game>(GridSizeLocal);

	// init world grid
	const FTransform GridOrigin = FTransform::Identity;
	GridVisual = GetWorld()->SpawnActorDeferred<ASG_Grid>(GridVisualClass, GridOrigin);
	check(GridVisual);
	
	GridVisual->SetModel(CoreGame->getGrid(), CellSize);
	GridVisual->FinishSpawning(GridOrigin);

	// set pawn location fitting grid in viewport
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	check(PlayerController);

	ASG_Pawn* ASGPawn = Cast<ASG_Pawn>(PlayerController->GetPawn());
	check(ASGPawn);
	check(CoreGame->getGrid());

	ASGPawn->UpdateLocation(CoreGame->getGrid()->getDimension(), CellSize, GridOrigin);
}
