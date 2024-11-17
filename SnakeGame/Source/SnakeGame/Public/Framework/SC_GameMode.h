// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Game.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/DataTable.h"
#include "InputActionValue.h"
#include "SC_GameMode.generated.h"

class ASG_Trap;
class ASG_Snake;
class AExponentialHeightFog;
class ASG_Grid;
class UInputAction;
class UInputMappingContext;
class ASG_Food;
class ASG_HUD;

UCLASS()
class SNAKEGAME_API ASC_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASC_GameMode();
	
	virtual void StartPlay() override;
	virtual void Tick(float DeltaSeconds) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category="TheSnake|General Settings")
	bool bOverrideUserSettings{false};
	
	UPROPERTY(EditDefaultsOnly, Category="TheSnake|General Settings", meta=(ClampMin="10", ClampMax="100", EditCondition="bOverrideUserSettings"))
	FUint32Point GridSize{10, 10};

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|General Settings", meta=(ClampMin="10", ClampMax="100", EditCondition="bOverrideUserSettings"))
	uint32 CellSize = 10;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|Design")
	TSubclassOf<ASG_Grid> GridVisualClass;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|Design")
	TSubclassOf<ASG_Snake> SnakeVisualClass;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|Design")
	TSubclassOf<ASG_Food> FoodVisualClass;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|Design")
	TSubclassOf<ASG_Trap> TrapVisualClass;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|Design")
	TObjectPtr<UDataTable> ColorsTable;

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|General Settings", meta=(ClampMin="4", ClampMax="10", EditCondition="bOverrideUserSettings"))
	uint32 SnakeDefaultSize{5};

	UPROPERTY(EditDefaultsOnly, Category="TheSnake|General Settings", meta=(ClampMin="0.01", ClampMax="10", EditCondition="bOverrideUserSettings"))
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
	TSharedPtr<SnakeGame::Game> CoreGame;
	SnakeGame::Input SnakeInput{SnakeGame::Input::Default};

	UPROPERTY()
	TObjectPtr<ASG_Grid> GridVisual;

	UPROPERTY()
	TObjectPtr<ASG_Snake> SnakeVisual;

	UPROPERTY()
	TObjectPtr<ASG_Food> FoodVisual;

	//UPROPERTY()
	//TObjectPtr<ASG_Trap> TrapVisual;

	UPROPERTY()
	TArray<TObjectPtr<ASG_Trap>> TrapsVisual;

	UPROPERTY()
	TObjectPtr<AExponentialHeightFog> Fog;

	UPROPERTY()
	TObjectPtr<ASG_HUD> HUD;

	uint32 ColorTableIndex{0};
	
	void UpdateColors() const;
	void FindFog();

	UFUNCTION(Exec, Category="SnakeGame|Console command")
	void NextColor();

	void SetupInput();
	void SpawnTrap(const TSharedPtr<SnakeGame::Trap>& InTrap);
	void OnMoveForward(const FInputActionValue& Value);
	void OnMoveRight(const FInputActionValue& Value);
	void OnResetGame(const FInputActionValue& Value);

	SnakeGame::Settings MakeSettings() const;

	void SubcribeOnGameEvents();
	
};
