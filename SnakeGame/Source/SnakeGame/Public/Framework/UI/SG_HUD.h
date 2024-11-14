// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Game.h"
#include "GameFramework/HUD.h"
#include "SG_HUD.generated.h"


class USG_GameOverWidget;
class USG_StartGameWidget;
class USG_GameplayWidget;

namespace SnakeGame
{
	class Game;
}


UENUM()
enum class EUIGameState : uint8
{
	StartGame = 0,
	GameInProgress,
	GameOver,
	GameCompleted
};


UCLASS()
class SNAKEGAME_API ASG_HUD : public AHUD
{
	GENERATED_BODY()

public:
	ASG_HUD();
	void SetModel(const TSharedPtr<SnakeGame::Game>& InGame);
	void SetInputKeyNames(const FString& ResetGameKeyName);
	
	virtual void Tick(float DeltaSeconds) override;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	TSubclassOf<USG_GameplayWidget> GameplayWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	TSubclassOf<USG_StartGameWidget> StartGameWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	TSubclassOf<USG_GameOverWidget> GameOverWidgetClass;

	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TObjectPtr<USG_GameplayWidget> GameplayWidget;

	UPROPERTY()
	TObjectPtr<USG_GameOverWidget> GameOverWidget;

	UPROPERTY()
	TMap<EUIGameState, TObjectPtr<UUserWidget>> GameWidgets; 

	TWeakPtr<SnakeGame::Game> Game;
	TObjectPtr<UUserWidget> CurrentWidget;
	EUIGameState GameState;

	void SetUIGameState(EUIGameState InGameState);
	
};
