// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/SC_GameMode.h"
#include "Core/Grid.h"
#include "Framework/GameWorld/SG_Grid.h"
#include "Framework/GameWorld/SG_Pawn.h"
#include "Framework/GameWorld/SG_WorldTypes.h"
#include "Framework/GameWorld/SG_Snake.h"
#include "Engine/ExponentialHeightFog.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

ASC_GameMode::ASC_GameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASC_GameMode::StartPlay()
{
	Super::StartPlay();

	check(GetWorld());

	// init core game
	CoreGame = MakeUnique<SnakeGame::Game>(MakeSettings());

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
}

void ASC_GameMode::UpdateColors() const
{
	const FName RowName = ColorsTable->GetRowNames()[ColorTableIndex];

	if (const auto ColorSet = ColorsTable->FindRow<FSnakeColors>(RowName, {}))
	{
		GridVisual->UpdateColors(*ColorSet);

		// update colors for snake
		SnakeVisual->UpdateColors(*ColorSet);

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
		
		Input->BindAction(MoveForwardInputAction, ETriggerEvent::Triggered, this, &ThisClass::OnMoveForward);
		Input->BindAction(MoveRightInputAction, ETriggerEvent::Triggered, this, &ThisClass::OnMoveRight);
		Input->BindAction(ResetGameInputAction, ETriggerEvent::Started, this, &ThisClass::OnResetGame);
	}
}

void ASC_GameMode::OnMoveForward(const FInputActionValue& Value)
{
	const FVector2D InputValue = Value.Get<FVector2D>();
	if (InputValue.X == 0.0) return;
	SnakeInput = SnakeGame::Input{0, static_cast<int8>(InputValue.X)};
}

void ASC_GameMode::OnMoveRight(const FInputActionValue& Value)
{
	const FVector2D InputValue = Value.Get<FVector2D>();
	if (InputValue.X == 0.0) return;
	SnakeInput = SnakeGame::Input{static_cast<int8>(InputValue.X), 0};
}

void ASC_GameMode::OnResetGame(const FInputActionValue& Value)
{
	if (const bool InputValue = Value.Get<bool>())
	{
		CoreGame.Reset(new SnakeGame::Game(MakeSettings()));
		check(CoreGame.IsValid());
		
		GridVisual->SetModel(CoreGame->getGrid(), CellSize);
		SnakeVisual->SetModel(CoreGame->getSnake(), CellSize, CoreGame->getGrid()->getDimension());
		SnakeInput = SnakeGame::Input{1, 0};
		NextColor();
	}
}

SnakeGame::Settings ASC_GameMode::MakeSettings() const
{
	SnakeGame::Settings GridSizeSettings;
	GridSizeSettings.gridSize = SnakeGame::Dimension{GridSize.X, GridSize.Y};
	GridSizeSettings.gameSpeed = GameSpeed;
	GridSizeSettings.snake.defaultSize = SnakeDefaultSize;
	// @TODO proper way to handle +1
	GridSizeSettings.snake.startPosition = SnakeGame::Position{GridSize.X/2 + 1, GridSize.Y/2 + 1};
	return GridSizeSettings;
}

void ASC_GameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (CoreGame.IsValid())
	{
		CoreGame->update(DeltaSeconds, SnakeInput);
	}
}
