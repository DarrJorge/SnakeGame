// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Game.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/DataTable.h"
#include "SC_GameMode.generated.h"

class ASG_Snake;
class AExponentialHeightFog;
class ASG_Grid;

UCLASS()
class SNAKEGAME_API ASC_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASC_GameMode();
	
	virtual void StartPlay() override;
	virtual void Tick(float DeltaSeconds) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category="TheSnake|SnakeGrid", meta=(ClampMin="10", ClampMax="100"))
	FUint32Point GridSize{10, 10};

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|SnakeGrid", meta=(ClampMin="10", ClampMax="100"))
	uint32 CellSize = 10;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|SnakeGrid")
	TSubclassOf<ASG_Grid> GridVisualClass;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|Snake")
	TSubclassOf<ASG_Snake> SnakeVisualClass;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|SnakeGrid")
	UDataTable* ColorsTable;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|Snake", meta=(ClampMin="4", ClampMax="10"))
	uint32 SnakeDefaultSize{5};

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|General", meta=(ClampMin="0.01", ClampMax="10"))
	float GameSpeed{1.0f};

private:
	TUniquePtr<SnakeGame::Game> CoreGame;
	SnakeGame::Input SnakeInput{1,0};

	UPROPERTY()
	ASG_Grid* GridVisual;

	UPROPERTY()
	ASG_Snake* SnakeVisual;

	UPROPERTY()
	AExponentialHeightFog* Fog;

	uint32 ColorTableIndex{0};
	
	void UpdateColors();
	void FindFog();

	UFUNCTION(Exec, Category="SnakeGame|Console command")
	void NextColor();
	
};
