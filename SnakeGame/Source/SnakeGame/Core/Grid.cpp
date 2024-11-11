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
				const auto index = posToIndex(x, y);
				m_cells[index] = CellType::Wall;
				m_indByType[CellType::Wall].Add(index);
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
		updateInternal(link->GetValue(), cellType);
		link = link->GetNextNode();
	}
}

void Grid::update(const Position& position, CellType cellType)
{
	resetCellsByType(cellType);
	updateInternal(position, cellType);
}

void Grid::updateInternal(const Position& position, CellType cellType)
{
	const uint32 index = posToIndex(position);
	m_cells[index] = cellType;
	m_indByType[cellType].Add(index);
}

void Grid::resetCellsByType(CellType cellType)
{
	for (uint32 i = 0; i < m_indByType[cellType].Num(); ++i)
	{
		const uint32 ind = m_indByType[cellType][i];
		m_cells[ind] = CellType::Empty;
	}
	m_indByType[cellType].Empty();
}

bool Grid::hitTest(const Position& position, CellType cellType) const
{
	return m_cells[posToIndex(position)] == cellType;
}

bool Grid::randomEmptyPosition(Position& position) const
{
	const auto gridSize = c_dimension.width * c_dimension.height;
	int numAttempts = 0;
	position = Position::Zero;
	
	while (numAttempts < gridSize)
	{
		const auto index = FMath::RandRange(0, gridSize - 1);
		if (m_cells[index] == CellType::Empty)
		{
			position = indexToPos(index);
			return true;
		}
		numAttempts++;
	}
	return false;
}

uint32 Grid::posToIndex(uint32 x, uint32 y) const
{
	return x + y * c_dimension.width;
}

uint32 Grid::posToIndex(const Position& position) const
{
	return posToIndex(position.x, position.y);
}

Position Grid::indexToPos(uint32 index) const
{
	auto pos = Position(index % c_dimension.width, index / c_dimension.width);
	UE_LOG(LogGrid, Warning, TEXT("index: %d, x:%d; y:%d"), index, pos.x, pos.y);
	return Position(index % c_dimension.width, index / c_dimension.width);
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
			case CellType::Food: symbol = 'F'; break;
			}
			line.AppendChar(symbol).AppendChar(' ');
		}
		UE_LOG(LogGrid, Display, TEXT("%s"), *line);
	}
#endif
}