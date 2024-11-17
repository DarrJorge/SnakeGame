// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SG_GameUserSettings.h"
#include "GameFramework/SaveGame.h"
#include "SG_SaveGame.generated.h"


UCLASS()
class SNAKEGAME_API USG_SaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	ECheckBoxState UseTrapProperty;
	EGameSpeed GameSpeedProperty;
	EGridSize GridSizeProperty;
	
};
