#include "Trap.h"

using namespace SnakeGame;


void Trap::setPosition(const Position& position)
{
	m_position = position;
}

Position Trap::getPosition() const
{
	return m_position;
}
