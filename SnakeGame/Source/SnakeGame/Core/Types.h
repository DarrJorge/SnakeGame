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
		Snake,
		Food,
	};

	struct Input
	{
		int8 x;
		int8 y;

		Input(int8 inX, int8 inY) : x(inX), y(inY){}

		bool opposite(const Input& rhs) const
		{
			return (x == -rhs.x && x != 0) || (y == -rhs.y && y != 0);
		}

		static const Input Default;
	};

	struct Position
	{
		uint32 x{0};
		uint32 y{0};
		
		Position(uint32 inX, uint32 inY) : x(inX), y(inY) {}
		Position() = default;
		
		Position& operator+=(const Position& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		bool operator==(const Position& rhs) const
		{
			return x == rhs.x && y == rhs.y;
		}

		static const Position Zero;

	};
	
	struct Settings
	{
		Dimension gridSize;

		struct Snake
		{
			uint32 defaultSize{4};
			Position startPosition{Position::Zero};
		} snake;

		float gameSpeed{1.0f};
	};


	using TPositionPtr = TDoubleLinkedList<Position>::TDoubleLinkedListNode;
	
	class TSnakeList : public TDoubleLinkedList<Position>
	{
	public:
		void MoveTail(TPositionPtr* tail, TPositionPtr* head, const Position& pos)
		{
			RemoveNode(tail);
			InsertNode(pos, head->GetNextNode());
		}
	};

	enum class GameplayEvent
	{
		GameOver = 0,
		GameCompleted,
		FootTaken
	};

	using GameplayEventCallback = TFunction<void(GameplayEvent)>;
}
