#pragma once

#include "CoreMinimal.h"
#include "Core/Types.h"
#include "Components/StaticMeshComponent.h"

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
	};
}
