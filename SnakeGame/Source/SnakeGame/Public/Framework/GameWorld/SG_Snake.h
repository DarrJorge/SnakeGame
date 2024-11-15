// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeGame/Core/Snake.h"
#include "Framework/GameWorld/SG_WorldTypes.h"
#include "SG_Snake.generated.h"

class ASG_SnakeLink;
class USG_ObjectPool;

UCLASS()
class SNAKEGAME_API ASG_Snake : public AActor
{
	GENERATED_BODY()
	
public:	
	ASG_Snake();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<ASG_SnakeLink> SnakeBodyClass;

public:
	void SetModel(const TSharedPtr<SnakeGame::Snake>& InSnake, uint32 InCellSize, const SnakeGame::Dimension& InDimension);
	
	virtual void Tick(float DeltaTime) override;

	void UpdateColors(const FSnakeColors& Colors);

	void Explode();

private:
	TWeakPtr<SnakeGame::Snake> Snake;
	uint32 CellSize;
	SnakeGame::Dimension Dimension;
	FLinearColor SnakeLinkColor;

	UPROPERTY()
	TArray<TObjectPtr<ASG_SnakeLink>> SnakeLinks;

	UPROPERTY()
	TObjectPtr<USG_ObjectPool> SnakeObjectPool{nullptr};

	void InitObjectPool();
};
