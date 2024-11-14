#pragma once

#include "CoreMinimal.h"
#include "Types.h"


namespace SnakeGame
{
	class IPositionRandomizer
	{
	public:
		virtual bool generatePosition(const Dimension& dim, const TArray<CellType>& cells, Position& position) const = 0;
		virtual ~IPositionRandomizer() = default;
	};

	class PositionRandomizer : public IPositionRandomizer
	{
	public:
		virtual bool generatePosition(const Dimension& dim, const TArray<CellType>& cells, Position& position) const override
		{
			const auto gridSize = dim.width * dim.height;
			int numAttempts = 0;
			position = Position::Zero;
	
			while (numAttempts < gridSize)
			{
				const auto index = FMath::RandRange(0, gridSize - 1);
				if (cells[index] == CellType::Empty)
				{
					position = indexToPos(index, dim);
					return true;
				}
				numAttempts++;
			}
			return false;
		}

	private:
		Position indexToPos(uint32 index, const Dimension& dim) const
		{
			return Position(index % dim.width, index / dim.width);
		}
	};

	using IPositionRandomizerPtr = TSharedPtr<IPositionRandomizer>;
}
