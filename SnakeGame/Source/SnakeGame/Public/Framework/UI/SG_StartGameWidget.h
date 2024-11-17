// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SG_StartGameWidget.generated.h"

class UCheckBox;
class UButton;
class UComboBoxString;

UCLASS()
class SNAKEGAME_API USG_StartGameWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> StartGameButton;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> QuitButton;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UComboBoxString> GameSpeedComboBox;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UComboBoxString> GridSizeComboBox;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCheckBox> UseTrapsCheckBox;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UWorld> GameLevel;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnStartGame();

	UFUNCTION()
	void OnQuitGame();

	UFUNCTION()
	void OnSelectionChanged(FString SelectedItem, ESelectInfo::Type SelectionType);

	UFUNCTION()
	void OnCheckBoxChecked(bool bIsChecked);

	void SaveSettings();
	
};
