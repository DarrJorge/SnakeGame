#include "Grid.h"

DEFINE_LOG_CATEGORY_STATIC(LogGrid, All, All);

using namespace SnakeGame;

Grid::Grid(const Dimension& dim)
	: c_dimension(Dimension{dim.width + 2, dim.height + 2})
{
	/*
	 * * * * * *
	 * 0 0 0 0 *
	 * 0 0 0 0 *
	 * 0 0 0 0 *
	 * * * * * *
	 */

	m_cells.Init(CellType::Empty, c_dimension.width * c_dimension.height);
	initWalls();
	printDebug();
}

void Grid::initWalls()
{
	for (int32 y = 0; y < c_dimension.height; ++y)
	{
		for (int32 x = 0; x < c_dimension.width; ++x)
		{
			if (x == 0 || x == c_dimension.width-1 || y == 0 || y == c_dimension.height-1)
			{
				m_cells[posToIndex(x, y)] = CellType::Wall;
			}
		}
	}
}

void Grid::printDebug()
{
#if !UE_BUILD_SHIPPING
	for (int32 y = 0; y < c_dimension.height; ++y)
	{
		FString line;
		for (int32 x = 0; x < c_dimension.width; ++x)
		{
			TCHAR symbol;
			switch (m_cells[posToIndex(x, y)])
			{
				case CellType::Empty: symbol = '0'; break;
				case CellType::Wall: symbol = '*'; break;
			}
			line.AppendChar(symbol).AppendChar(' ');
		}
		UE_LOG(LogGrid, Display, TEXT("%s"), *line);
	}
#endif
}

int32 Grid::posToIndex(int32 x, int32 y) const
{
	return x + y * c_dimension.width;
}
