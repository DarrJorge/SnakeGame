// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/SC_GameMode.h"
#include "Core/Grid.h"
#include "Framework/GameWorld/SG_Grid.h"
#include "Framework/GameWorld/SG_Pawn.h"
#include "Framework/GameWorld/SG_WorldTypes.h"
#include "Framework/GameWorld/SG_Snake.h"
#include "Framework/GameWorld/SG_Food.h"
#include "Engine/ExponentialHeightFog.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Framework/UI/SG_HUD.h"
#include "Framework/GameWorld/SG_Utils.h"
#include "Framework/SG_GameUserSettings.h"

DEFINE_LOG_CATEGORY_STATIC(LogSnakeGameMode, All, All);

ASC_GameMode::ASC_GameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASC_GameMode::StartPlay()
{
	Super::StartPlay();

	check(GetWorld());

	// init core game
	CoreGame = MakeShared<SnakeGame::Game>(MakeSettings());
	SubcribeOnGameEvents();

	// init world grid
	const FTransform GridOrigin = FTransform::Identity;
	GridVisual = GetWorld()->SpawnActorDeferred<ASG_Grid>(GridVisualClass, GridOrigin);
	check(GridVisual);
	GridVisual->SetModel(CoreGame->getGrid(), CellSize);
	GridVisual->FinishSpawning(GridOrigin);

	// init world snake
	SnakeVisual = GetWorld()->SpawnActorDeferred<ASG_Snake>(SnakeVisualClass, GridOrigin);
	check(SnakeVisual);
	SnakeVisual->SetModel(CoreGame->getSnake(), CellSize, CoreGame->getGrid()->getDimension());
	SnakeVisual->FinishSpawning(GridOrigin);

	// init world food
	FoodVisual = GetWorld()->SpawnActorDeferred<ASG_Food>(FoodVisualClass, GridOrigin);
	check(FoodVisual);
	FoodVisual->SetModel(CoreGame->getFood(), CellSize, CoreGame->getGrid()->getDimension());
	FoodVisual->FinishSpawning(GridOrigin);
	
	// set pawn location fitting grid in viewport
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	check(PlayerController);

	ASG_Pawn* ASGPawn = Cast<ASG_Pawn>(PlayerController->GetPawn());
	check(ASGPawn);
	check(CoreGame->getGrid());
	ASGPawn->UpdateLocation(CoreGame->getGrid()->getDimension(), CellSize, GridOrigin);

	// find fog
	FindFog();
	
	// update colors
	check(ColorsTable);
	const auto RowsCount = ColorsTable->GetRowNames().Num();
	check(RowsCount >= 1);
	
	ColorTableIndex = FMath::RandRange(0, RowsCount - 1);
	UpdateColors();

	SetupInput();

	HUD = Cast<ASG_HUD>(PlayerController->GetHUD());
	HUD->SetModel(CoreGame);
	
	const FString ResetGameKeyName = SnakeGame::SG_Utils::FindActionKeyName(MappingContext, ResetGameInputAction);
	HUD->SetInputKeyNames(ResetGameKeyName);

	SnakeGame::SG_Utils::SetUIInput(GetWorld(), false);
}

void ASC_GameMode::UpdateColors() const
{
	const FName RowName = ColorsTable->GetRowNames()[ColorTableIndex];

	if (const auto ColorSet = ColorsTable->FindRow<FSnakeColors>(RowName, {}))
	{
		GridVisual->UpdateColors(*ColorSet);
		SnakeVisual->UpdateColors(*ColorSet);
		FoodVisual->UpdateColor(ColorSet->FoodColor);

		// update scene ambient color via fog
		if (Fog && Fog->GetComponent())
		{
			Fog->GetComponent()->SkyAtmosphereAmbientContributionColorScale = ColorSet->SkyAtmosphereColor;
			Fog->MarkComponentsRenderStateDirty();
		}
	}
}

void ASC_GameMode::FindFog()
{
	TArray<AActor*> Fogs;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AExponentialHeightFog::StaticClass(), Fogs);

	if (Fogs.Num() > 0)
	{
		Fog = Cast<AExponentialHeightFog>(Fogs[0]);
	}
}

void ASC_GameMode::NextColor()
{
	if (ColorsTable)
	{
		ColorTableIndex = (ColorTableIndex + 1) % ColorsTable->GetRowNames().Num();
		UpdateColors();
	}
}

void ASC_GameMode::SetupInput()
{
	if (!GetWorld()) return;
	
	if (const auto* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		if (auto* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			InputSystem->AddMappingContext(MappingContext, 0);
		}

		auto* Input = Cast<UEnhancedInputComponent>(PlayerController->InputComponent);
		check(Input);
		
		Input->BindAction(MoveForwardInputAction, ETriggerEvent::Started, this, &ThisClass::OnMoveForward);
		Input->BindAction(MoveRightInputAction, ETriggerEvent::Started, this, &ThisClass::OnMoveRight);
		Input->BindAction(ResetGameInputAction, ETriggerEvent::Started, this, &ThisClass::OnResetGame);
	}
}

void ASC_GameMode::OnMoveForward(const FInputActionValue& Value)
{
	const float InputValue = Value.Get<float>();
	if (InputValue == 0.0f) return;
	SnakeInput = SnakeGame::Input{0, static_cast<int8>(InputValue)};
}

void ASC_GameMode::OnMoveRight(const FInputActionValue& Value)
{
	const float InputValue = Value.Get<float>();
	if (InputValue == 0.0f) return;
	SnakeInput = SnakeGame::Input{static_cast<int8>(InputValue), 0};
}

void ASC_GameMode::OnResetGame(const FInputActionValue& Value)
{
	if (const bool InputValue = Value.Get<bool>())
	{
		CoreGame = MakeShared<SnakeGame::Game>(MakeSettings());
		check(CoreGame.IsValid());
		SubcribeOnGameEvents();
		HUD->SetModel(CoreGame);
		
		GridVisual->SetModel(CoreGame->getGrid(), CellSize);
		SnakeVisual->SetModel(CoreGame->getSnake(), CellSize, CoreGame->getGrid()->getDimension());
		FoodVisual->SetModel(CoreGame->getFood(), CellSize, CoreGame->getGrid()->getDimension());
		SnakeInput = SnakeGame::Input{SnakeGame::Input::Default};
		NextColor();
		
		SnakeGame::SG_Utils::SetUIInput(GetWorld(), false);
	}
}

SnakeGame::Settings ASC_GameMode::MakeSettings() const
{
	SnakeGame::Settings GridSizeSettings;
#if WITH_EDITOR
	if (bOverrideUserSettings)
	{
		GridSizeSettings.gridSize = SnakeGame::Dimension{GridSize.X, GridSize.Y};
		GridSizeSettings.gameSpeed = GameSpeed;
	}
	else
#endif
		if (const auto* UserSettings = USG_GameUserSettings::Get())
	{
		GridSizeSettings.gridSize = UserSettings->GridSize();
		GridSizeSettings.gameSpeed = UserSettings->GameSpeed();
	}
	
	GridSizeSettings.snake.defaultSize = SnakeDefaultSize;
	GridSizeSettings.snake.startPosition = SnakeGame::Grid::center(GridSizeSettings.gridSize.width, GridSizeSettings.gridSize.height);
	return GridSizeSettings;
}

void ASC_GameMode::SubcribeOnGameEvents()
{
	using namespace SnakeGame;

	CoreGame->subcribeOnGameplayEvent([&](GameplayEvent event)
	{
		switch (event)
		{
		case GameplayEvent::GameOver:
			UE_LOG(LogSnakeGameMode, Display, TEXT("------------------ GAME OVER ------------------"));
			UE_LOG(LogSnakeGameMode, Display, TEXT("------------------ SCORE: %i ------------------"), CoreGame->getScore());
			SnakeVisual->Explode();
			FoodVisual->Hide();
			SG_Utils::SetUIInput(GetWorld(), true);
			break;
			
		case GameplayEvent::GameCompleted:
			UE_LOG(LogSnakeGameMode, Display, TEXT("------------------ GAME COMPLETED ------------------"));
			UE_LOG(LogSnakeGameMode, Display, TEXT("------------------ SCORE: %i ------------------"), CoreGame->getScore());
			break;
			
		case GameplayEvent::FootTaken:
			UE_LOG(LogSnakeGameMode, Display, TEXT("------------------ FOOD TAKEN ------------------"));
			FoodVisual->Explode();
			break;
		}
	});
}

void ASC_GameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (CoreGame.IsValid())
	{
		CoreGame->update(DeltaSeconds, SnakeInput);
	}
}
