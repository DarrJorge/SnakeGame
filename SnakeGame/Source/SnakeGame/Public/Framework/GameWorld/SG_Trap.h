// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeGame/Core/Trap.h"
#include "SG_Trap.generated.h"

class UStaticMeshComponent;
class UNiagaraSystem;

UCLASS()
class SNAKEGAME_API ASG_Trap : public AActor
{
	GENERATED_BODY()
	
public:	
	ASG_Trap();

protected:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Origin;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="VFX")
	TObjectPtr<UNiagaraSystem> ExplosionEffect;

public:
	void SetModel(const TSharedPtr<SnakeGame::Trap>& InTrap, uint32 InCellSize, const SnakeGame::Dimension& Dims);
	void UpdateColor(const FLinearColor& Color);
	
	virtual void Tick(float DeltaTime) override;

	void Explode();

	void Hide();

private:
	TWeakPtr<SnakeGame::Trap> Trap;
	uint32 CellSize;
	SnakeGame::Dimension Dimension;
	FLinearColor TrapColor;

	FVector GetTrapWorldLocation() const;

	

};
