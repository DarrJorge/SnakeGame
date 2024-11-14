// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/UI/SG_GameOverWidget.h"
#include "Components/TextBlock.h"
#include "Framework/GameWorld/SG_Utils.h"

using namespace SnakeGame;

void USG_GameOverWidget::SetScore(uint32 Score)
{
	if (ScoreText)
	{
		ScoreText->SetText(SG_Utils::FormatScore(Score));
	}
}

void USG_GameOverWidget::SetResetGameKeyName(const FString& ResetGameKeyName)
{
	if (ResetGameText)
	{
		const FString ResetGameInfo = FString::Printf(TEXT("press <%s> to reset"), *ResetGameKeyName.ToLower());
		ResetGameText->SetText(FText::FromString(ResetGameInfo));
	}
}
