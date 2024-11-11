// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Game.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/DataTable.h"
#include "InputActionValue.h"
#include "SC_GameMode.generated.h"

class ASG_Snake;
class AExponentialHeightFog;
class ASG_Grid;
class UInputAction;
class UInputMappingContext;
class ASG_Food;

UCLASS()
class SNAKEGAME_API ASC_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASC_GameMode();
	
	virtual void StartPlay() override;
	virtual void Tick(float DeltaSeconds) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category="TheSnake|SetUpSnakeGrid", meta=(ClampMin="10", ClampMax="100"))
	FUint32Point GridSize{10, 10};

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|SetUpSnakeGrid", meta=(ClampMin="10", ClampMax="100"))
	uint32 CellSize = 10;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|Design")
	TSubclassOf<ASG_Grid> GridVisualClass;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|Design")
	TSubclassOf<ASG_Snake> SnakeVisualClass;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|Design")
	TSubclassOf<ASG_Food> FoodVisualClass;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|Design")
	TObjectPtr<UDataTable> ColorsTable;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|Snake", meta=(ClampMin="4", ClampMax="10"))
	uint32 SnakeDefaultSize{5};

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|General", meta=(ClampMin="0.01", ClampMax="10"))
	float GameSpeed{1.0f};

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|SnakeInput")
	TObjectPtr<UInputAction> MoveForwardInputAction;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|SnakeInput")
	TObjectPtr<UInputAction> MoveRightInputAction;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|SnakeInput")
	TObjectPtr<UInputAction> ResetGameInputAction;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|SnakeInput")
	TObjectPtr<UInputMappingContext> MappingContext;

private:
	TUniquePtr<SnakeGame::Game> CoreGame;
	SnakeGame::Input SnakeInput{SnakeGame::Input::Default};

	UPROPERTY()
	ASG_Grid* GridVisual;

	UPROPERTY()
	ASG_Snake* SnakeVisual;

	UPROPERTY()
	ASG_Food* FoodVisual;

	UPROPERTY()
	AExponentialHeightFog* Fog;

	uint32 ColorTableIndex{0};
	
	void UpdateColors() const;
	void FindFog();

	UFUNCTION(Exec, Category="SnakeGame|Console command")
	void NextColor();

	void SetupInput();
	void OnMoveForward(const FInputActionValue& Value);
	void OnMoveRight(const FInputActionValue& Value);
	void OnResetGame(const FInputActionValue& Value);

	SnakeGame::Settings MakeSettings() const;
	
};
