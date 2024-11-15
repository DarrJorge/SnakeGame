// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Framework/UI/SG_MenuHUD.h"
#include "Framework/UI/SG_StartGameWidget.h"

void ASG_MenuHUD::BeginPlay()
{
	Super::BeginPlay();

	StartGameWidget = CreateWidget<USG_StartGameWidget>(GetWorld(), StartGameWidgetClass);
	check(StartGameWidget);
	StartGameWidget->AddToViewport();
}
