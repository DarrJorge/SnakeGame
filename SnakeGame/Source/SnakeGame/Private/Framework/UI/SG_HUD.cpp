// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/UI/SG_HUD.h"
#include "Framework/UI/SG_GameplayWidget.h"
#include "Framework/UI/SG_GameOverWidget.h"
#include "Core/Game.h"


ASG_HUD::ASG_HUD()
{
	PrimaryActorTick.TickInterval = 1.f;
}

void ASG_HUD::BeginPlay()
{
	Super::BeginPlay();

	GameplayWidget = CreateWidget<USG_GameplayWidget>(GetWorld(), GameplayWidgetClass);
	check(GameplayWidget);
	GameWidgets.Add(EUIGameState::GameInProgress, GameplayWidget);

	GameOverWidget = CreateWidget<USG_GameOverWidget>(GetWorld(), GameOverWidgetClass);
	check(GameOverWidget);
	GameWidgets.Add(EUIGameState::GameOver, GameOverWidget);

	for (auto& [UIState, GameWidget] : GameWidgets)
	{
		if (GameWidget)
		{
			GameWidget->AddToViewport();
			GameWidget->SetVisibility(ESlateVisibility::Collapsed);
		}
	}
}

void ASG_HUD::SetModel(const TSharedPtr<SnakeGame::Game>& InGame)
{
	if (!InGame) return;
	using namespace SnakeGame;

	Game = InGame;
	
	SetUIGameState(EUIGameState::GameInProgress);
	GameplayWidget->SetScore(InGame->getScore());
	GameOverWidget->SetScore(InGame->getScore());

	InGame->subcribeOnGameplayEvent([&](GameplayEvent Event)
	{
		switch (Event)
		{
			case GameplayEvent::FootTaken:
				GameplayWidget->SetScore(InGame->getScore());
				break;

			case GameplayEvent::GameOver:
				SetUIGameState(EUIGameState::GameOver);
				GameOverWidget->SetScore(InGame->getScore());
				break;
			
			case GameplayEvent::GameCompleted:
				break;
			
			default: ;
		}
	});
}

void ASG_HUD::SetInputKeyNames(const FString& ResetGameKeyName)
{
	GameOverWidget->SetResetGameKeyName(ResetGameKeyName);
}

void ASG_HUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (Game.IsValid() && GameState == EUIGameState::GameInProgress)
	{
		GameplayWidget->SetGameTime(Game.Pin()->gameTime());
	}
}

void ASG_HUD::SetUIGameState(EUIGameState InGameState)
{
	GameState = InGameState;
	
	if (CurrentWidget)
	{
		CurrentWidget->SetVisibility(ESlateVisibility::Collapsed);
	}

	if (GameWidgets.Contains(InGameState))
	{
		CurrentWidget = GameWidgets[InGameState];
		CurrentWidget->SetVisibility(ESlateVisibility::Visible);
	}
}
