#pragma once

#include "CoreMinimal.h"
#include "Types.h"

namespace SnakeGame
{
	class Food
	{
	public:
		Food() = default;

		void setPosition(const Position& position);
		Position getPosition() const;

	private:
		Position m_position{Position::Zero};
	
	};
}