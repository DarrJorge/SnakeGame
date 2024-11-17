// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/SG_GameUserSettings.h"

#include "Framework/SG_SaveGame.h"
#include "GameFramework/SaveGame.h"
#include "Kismet/GameplayStatics.h"

USG_GameUserSettings::USG_GameUserSettings()
{
	check(GameSpeeds.Num() == StaticEnum<EGameSpeed>()->NumEnums() - 1);
	check(GridSizes.Num() == StaticEnum<EGridSize>()->NumEnums() - 1);

	// load settings from file
	if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, 0))
	{
		if (auto* SaveGame = UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0))
		{
			if (auto* SGSaveGame = Cast<USG_SaveGame>(SaveGame))
			{
				CurrentSpeed = GameSpeeds[SGSaveGame->GameSpeedProperty];
				CurrentGridSize = GridSizes[SGSaveGame->GridSizeProperty];
				bUseTraps = SGSaveGame->UseTrapProperty == ECheckBoxState::Checked;
			}
		}
	}
}

USG_GameUserSettings* USG_GameUserSettings::Get()
{
	return GEngine ? Cast<USG_GameUserSettings>(GEngine->GetGameUserSettings()) : nullptr;
}

bool USG_GameUserSettings::TrySaveSnakeSettings(FSettingsData InData)
{
	CurrentSpeed = GameSpeeds[InData.GameSpeed];
	CurrentGridSize = GridSizes[InData.GridSize];
	bUseTraps = InData.UseTrapsState == ECheckBoxState::Checked;

	// save settings in file
	auto* SaveGame = UGameplayStatics::CreateSaveGameObject(USG_SaveGame::StaticClass());
	if (!SaveGame) return false;
	auto* SGSaveGame = Cast<USG_SaveGame>(SaveGame);
	if (!SGSaveGame) return false;

	SGSaveGame->GameSpeedProperty = InData.GameSpeed;
	SGSaveGame->GridSizeProperty = InData.GridSize;
	SGSaveGame->UseTrapProperty = InData.UseTrapsState;

	return UGameplayStatics::SaveGameToSlot(SGSaveGame, SaveSlotName, 0);
}
