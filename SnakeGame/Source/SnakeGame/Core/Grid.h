#pragma once

#include "CoreMinimal.h"
#include "Types.h"

namespace SnakeGame
{
	class Grid
	{
	public:
		Grid(const Dimension& dim);

		Dimension getDimension() const { return c_dimension; }

		void printDebug();

		void update(const TPositionPtr* links, CellType cellType);
		void update(const Position& position, CellType cellType);
		bool hitTest(const Position& position, CellType cellType) const;

		bool randomEmptyPosition(Position& position) const;
		
		static Position center(uint32 width, uint32 height)
		{
			return Position(width / 2 + 1, height / 2 + 1);
		}

	private:
		const Dimension c_dimension;
		TArray<CellType> m_cells;
		TMap<CellType, TArray<uint32>> m_indByType = {
			{CellType::Snake, {}},
			{CellType::Wall, {}},
			{CellType::Food, {}}
		};

		void initWalls();
		void resetCellsByType(CellType cellType);
		void updateInternal(const Position& position, CellType cellType);
		
		FORCEINLINE uint32 posToIndex(uint32 x, uint32 y) const;
		FORCEINLINE uint32 posToIndex(const Position& position) const;
		FORCEINLINE Position indexToPos(uint32 index) const;
	};
}
