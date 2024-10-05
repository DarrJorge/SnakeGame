#pragma once

namespace SnakeGame
{
	struct Dimension
	{
		int32 width;
		int32 height;
	};

	enum class CellType
	{
		Empty = 0,
		Wall
		// Food,
		// Snake
	};

	struct Settings
	{
		Dimension gridSize;
	};
}
