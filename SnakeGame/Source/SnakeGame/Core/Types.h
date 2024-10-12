#pragma once

#include "Containers/List.h"

namespace SnakeGame
{
	struct Dimension
	{
		uint32 width;
		uint32 height;
	};

	enum class CellType
	{
		Empty = 0,
		Wall,
		Snake
		// Food,
	};

	struct Input
	{
		int8 x;
		int8 y;
	};

	struct Position
	{
		uint32 x;
		uint32 y;
		
		Position(uint32 inX, uint32 inY) : x(inX), y(inY) {}
		Position& operator+=(const Position& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

	};
	
	struct Settings
	{
		Dimension gridSize;

		struct Snake
		{
			uint32 defaultSize{4};
			Position startPosition{0,0};
		} snake;

		float gameSpeed{1.0f};
	};

	using TSnakeList = TDoubleLinkedList<Position>;
	using TPositionPtr = TSnakeList::TDoubleLinkedListNode;
}
