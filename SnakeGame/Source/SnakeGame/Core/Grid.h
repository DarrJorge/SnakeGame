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
		bool hitTest(const Position& position, CellType cellType) const;

	private:
		const Dimension c_dimension;
		TArray<CellType> m_cells;

		void initWalls();
		void resetCellsByType(CellType cellType);
		
		FORCEINLINE uint32 posToIndex(uint32 x, uint32 y) const;
		FORCEINLINE uint32 posToIndex(const Position& position) const;
	};
}
