// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/UI/SG_StartGameWidget.h"
#include "Components/Button.h"
#include "Components/CheckBox.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/ComboBoxString.h"
#include "Framework/SG_GameUserSettings.h"

DEFINE_LOG_CATEGORY_STATIC(LogStartGameWidget, All, All);

void USG_StartGameWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	check(QuitButton);
	QuitButton->OnClicked.AddDynamic(this, &ThisClass::OnQuitGame);

	auto* UserSettings = USG_GameUserSettings::Get();
	if (!UserSettings)
	{
		UE_LOG(LogStartGameWidget, Error, TEXT("Object UserSettings is nullptr."))
		return;
	}

	check(StartGameButton);
	StartGameButton->OnClicked.AddDynamic(this, &ThisClass::OnStartGame);
	
	check(GameSpeedComboBox);
	GameSpeedComboBox->ClearOptions();
	for (const auto& Option : UserSettings->GameSpeedOptions())
	{
		GameSpeedComboBox->AddOption(Option);
	}
	GameSpeedComboBox->SetSelectedOption(UserSettings->GetCurrentGameSpeedOption());
	GameSpeedComboBox->OnSelectionChanged.AddDynamic(this, &ThisClass::OnSelectionChanged);

	check(GridSizeComboBox);
	GridSizeComboBox->ClearOptions();
	for (const auto& Option : UserSettings->GridSizesOptions())
	{
		GridSizeComboBox->AddOption(Option);
	}
	GridSizeComboBox->SetSelectedOption(UserSettings->GetCurrentGridSizeOption());
	GridSizeComboBox->OnSelectionChanged.AddDynamic(this, &ThisClass::OnSelectionChanged);

	check(UseTrapsCheckBox);
	UseTrapsCheckBox->SetCheckedState(UserSettings->GetUseTrapsState());
	UseTrapsCheckBox->OnCheckStateChanged.AddDynamic(this, &ThisClass::OnCheckBoxChecked);
}

void USG_StartGameWidget::OnStartGame()
{
	UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(), GameLevel);
}

void USG_StartGameWidget::OnQuitGame()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}

void USG_StartGameWidget::OnSelectionChanged(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	if (SelectionType == ESelectInfo::OnMouseClick)
	{
		SaveSettings();
	}
}

void USG_StartGameWidget::OnCheckBoxChecked(bool bIsChecked)
{
	SaveSettings();
}

void USG_StartGameWidget::SaveSettings()
{
	if (auto* UserSettings = USG_GameUserSettings::Get())
	{
		const EGameSpeed GameSpeed = UserSettings->GameSpeedByName(GameSpeedComboBox->GetSelectedOption());
		const EGridSize GridSize = UserSettings->GridSizeByName(GridSizeComboBox->GetSelectedOption());
		const ECheckBoxState UseTrapsState = UseTrapsCheckBox->GetCheckedState();
		
		if (!UserSettings->TrySaveSnakeSettings(FSettingsData(GameSpeed, GridSize, UseTrapsState)))
		{
			UE_LOG(LogStartGameWidget, Error, TEXT("Can't save settings to file."))
		}
	}
}
