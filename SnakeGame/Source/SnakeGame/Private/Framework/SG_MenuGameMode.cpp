// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/SG_MenuGameMode.h"
#include "Framework/GameWorld/SG_Utils.h"

void ASG_MenuGameMode::StartPlay()
{
	Super::StartPlay();

	SnakeGame::SG_Utils::SetUIInput(GetWorld(), true);
}
