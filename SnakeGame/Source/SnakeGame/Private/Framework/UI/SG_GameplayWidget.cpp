// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/UI/SG_GameplayWidget.h"
#include "Components/TextBlock.h"
#include "Framework/GameWorld/SG_Utils.h"

using namespace SnakeGame;

void USG_GameplayWidget::SetGameTime(float Seconds)
{
	if (TimeText)
	{
		TimeText->SetText(SG_Utils::FormatSeconds(Seconds));
	}
}

void USG_GameplayWidget::SetScore(uint32 Score)
{
	if (ScoreText)
	{
		ScoreText->SetText(SG_Utils::FormatScore(Score));
	}
}
