// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SG_GameplayWidget.generated.h"


class UTextBlock;

UCLASS()
class SNAKEGAME_API USG_GameplayWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetGameTime(float Seconds);
	void SetScore(uint32 Score);

protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> TimeText;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UTextBlock> ScoreText;
	
};
