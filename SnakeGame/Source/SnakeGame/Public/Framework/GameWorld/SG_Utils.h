#pragma once

#include "CoreMinimal.h"
#include "Core/Types.h"
#include "Components/StaticMeshComponent.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedActionKeyMapping.h"

namespace SnakeGame
{
	struct Position;
	
	class SG_Utils
	{
	public:
		static FVector LinkPositionToVector(const Position& Position, uint32 CellSize, const Dimension& Dimension)
		{
			const double PositionX = (Dimension.height - 1 - Position.y) * CellSize;
			return FVector(PositionX, Position.x * CellSize, 0.0) + FVector(CellSize * 0.5);
		}

		static void ScaleMesh(UStaticMeshComponent* Mesh, const FVector& WorldSize)
		{
			if (Mesh && Mesh->GetStaticMesh())
			{
				const FBox Box = Mesh->GetStaticMesh()->GetBoundingBox();
				const auto Size = Box.GetSize();
				Mesh->SetRelativeScale3D(FVector(WorldSize / Size));
			}
		}

		static FText FormatSeconds(float TimeSeconds)
		{
			const int32 TotalSeconds = FMath::RoundToInt(TimeSeconds);
			const int32 Minutes = TotalSeconds / 60;
			const int32 Seconds = TotalSeconds % 60;
			const FString FormattedTime = FString::Printf(TEXT("%02i:%02i"), Minutes, Seconds);
			return FText::FromString(FormattedTime);
		}

		static FText FormatScore(uint32 Score)
		{
			const FString FormattedScore = FString::Printf(TEXT("%02i"), Score);
			return FText::FromString(FormattedScore);
		}

		static FString FindActionKeyName(const TObjectPtr<UInputMappingContext>& InputMapping, const TObjectPtr<UInputAction>& Action)
		{
			auto* FoundAction = InputMapping->GetMappings().FindByPredicate([&](const FEnhancedActionKeyMapping& Mapping)
				{ return Mapping.Action == Action; });

			return FoundAction ? FoundAction->Key.GetDisplayName().ToString() : FString("None");
		}

		static void SetUIInput(UWorld* WorldContextObject, bool Enabled)
		{
			if (!WorldContextObject) return;
			if (auto* PC = WorldContextObject->GetFirstPlayerController())
			{
				PC->SetShowMouseCursor(Enabled);
				if (Enabled)
				{
					PC->SetInputMode(FInputModeGameAndUI().SetHideCursorDuringCapture(false));
				}
				else
				{
					PC->SetInputMode(FInputModeGameOnly());
				}
			}
		}
	};
}
