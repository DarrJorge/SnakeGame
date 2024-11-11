// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeGame/Core/Food.h"
#include "SG_Food.generated.h"

class UStaticMeshComponent;

UCLASS()
class SNAKEGAME_API ASG_Food : public AActor
{
	GENERATED_BODY()
	
public:	
	ASG_Food();

protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Origin;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* FoodMesh;

public:
	void SetModel(const TSharedPtr<SnakeGame::Food>& InFood, uint32 InCellSize, const SnakeGame::Dimension& Dims);
	void UpdateColor(const FLinearColor& Color);
	
	virtual void Tick(float DeltaTime) override;

private:
	TWeakPtr<SnakeGame::Food> Food;
	uint32 CellSize;
	SnakeGame::Dimension Dimension;

};
