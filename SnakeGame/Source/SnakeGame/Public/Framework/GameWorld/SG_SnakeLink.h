// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SG_SnakeLink.generated.h"

class UStaticMeshComponent;

UCLASS()
class SNAKEGAME_API ASG_SnakeLink : public AActor
{
	GENERATED_BODY()
	
public:	
	ASG_SnakeLink();

	void UpdateScale(uint32 CellSize) const;
	void UpdateColor(const FLinearColor& Color) const;

protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Origin;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LinkMesh;
	
};
