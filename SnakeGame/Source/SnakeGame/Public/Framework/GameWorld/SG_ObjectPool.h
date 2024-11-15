// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SG_ObjectPool.generated.h"


UCLASS()
class SNAKEGAME_API USG_ObjectPool : public UObject
{
	GENERATED_BODY()

public:

	template<typename ActorType>
	void Push(ActorType* Actor)
	{
		if (!Actor) return;
		Actor->SetActorHiddenInGame(true);
		Pool.Add(Actor);
	}

	template<typename ActorType>
	ActorType* Pop(UWorld* World, const FTransform& Transform, const TSubclassOf<AActor>& ActorClass)
	{
		if (!World) return nullptr;
		
		ActorType* Actor = Pool.IsEmpty()
			? World->SpawnActor<ActorType>(ActorClass, Transform)
			: Cast<ActorType>(Pool.Pop().Get());
		
		check(Actor);
		Actor->SetActorHiddenInGame(false);
		Actor->SetActorTransform(Transform);
		return Actor;
	}

	template<typename ActorType>
	void Reserve(UWorld* World, int32 Num, const TSubclassOf<AActor>& ActorClass)
	{
		if (!World) return;
		
		for (int32 i = 0; i < Num; ++i)
		{
			ActorType* Actor = World->SpawnActor<ActorType>(ActorClass, FTransform::Identity);
			Push(Actor);
		}
	}

private:
	UPROPERTY()
	TArray<TObjectPtr<AActor>> Pool;
	
};
