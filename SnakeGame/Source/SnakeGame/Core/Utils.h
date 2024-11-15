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
		/*virtual bool generatePosition(const Dimension& dim, const TArray<CellType>& cells, Position& position) const override
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
		}*/

		virtual bool generatePosition(const Dimension& dim, const TArray<CellType>& cells, Position& position) const override
		{
			const uint32 startX = FMath::RandRange(1, dim.width - 2);
			const uint32 startY = FMath::RandRange(1, dim.height - 2);
			Position randomPosition = {startX, startY};

			do
			{
				const uint32 index = posToIndex(randomPosition, dim);
				if (cells[index] == CellType::Empty)
				{
					position = randomPosition;
					return true;
				}

				if (++randomPosition.x > dim.width - 2)
				{
					randomPosition.x = 1;
					if (++randomPosition.y > dim.height - 2)
					{
						randomPosition.y = 1;
					}
				}
			} while (randomPosition.x != startX || randomPosition.y != startY);
			return false;
		}

	private:
		FORCEINLINE Position indexToPos(uint32 index, const Dimension& dim) const
		{
			return Position(index % dim.width, index / dim.width);
		}

		FORCEINLINE uint32 posToIndex(const Position& position, const Dimension& dim) const
		{
			return position.x + position.y * dim.width;
		}
	};

	using IPositionRandomizerPtr = TSharedPtr<IPositionRandomizer>;
}
