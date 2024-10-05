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

	private:
		const Dimension c_dimension;
		TArray<CellType> m_cells;

		void initWalls();
		void printDebug();
		int32 posToIndex(int32 x, int32 y) const;
	};
}
