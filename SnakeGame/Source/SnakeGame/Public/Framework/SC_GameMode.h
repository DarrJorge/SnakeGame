// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Game.h"
#include "GameFramework/GameModeBase.h"
#include "SC_GameMode.generated.h"

class ASG_Grid;

UCLASS()
class SNAKEGAME_API ASC_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void StartPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category="SnakeGrid", meta=(ClampMin="10", ClampMax="100"))
	FIntPoint GridSize{10, 10};

	UPROPERTY(EditDefaultsOnly, Category="SnakeGrid", meta=(ClampMin="10", ClampMax="100"))
	int32 CellSize = 10;

	UPROPERTY(EditDefaultsOnly, Category="SnakeGrid")
	TSubclassOf<ASG_Grid> GridVisualClass;

private:
	TUniquePtr<SnakeGame::Game> CoreGame;

	UPROPERTY()
	ASG_Grid* GridVisual;
	
};
