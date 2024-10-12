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

void Grid::update(const TPositionPtr* links, CellType cellType)
{
	resetCellsByType(cellType);
	auto* link = links;
	
	while (link)
	{
		const auto index = posToIndex(link->GetValue());
		m_cells[index] = cellType;
		link = link->GetNextNode();
	}
}

void Grid::resetCellsByType(CellType cellType)
{
	// need optimize later
	for (auto& cell : m_cells)
	{
		if (cell == cellType)
		{
			cell = CellType::Empty;
		}
	}
}

bool Grid::hitTest(const Position& position, CellType cellType) const
{
	return m_cells[posToIndex(position)] == cellType;
}

uint32 Grid::posToIndex(uint32 x, uint32 y) const
{
	return x + y * c_dimension.width;
}

uint32 Grid::posToIndex(const Position& position) const
{
	return posToIndex(position.x, position.y);
}

void Grid::printDebug()
{
#if !UE_BUILD_SHIPPING
	for (uint32 y = 0; y < c_dimension.height; ++y)
	{
		FString line;
		for (uint32 x = 0; x < c_dimension.width; ++x)
		{
			TCHAR symbol;
			switch (m_cells[posToIndex(x, y)])
			{
			case CellType::Empty: symbol = '0'; break;
			case CellType::Wall: symbol = '*'; break;
			case CellType::Snake: symbol = '_'; break;
			}
			line.AppendChar(symbol).AppendChar(' ');
		}
		UE_LOG(LogGrid, Display, TEXT("%s"), *line);
	}
#endif
}