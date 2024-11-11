#include "Snake.h"

using namespace SnakeGame;

Snake::Snake(const Settings::Snake& settings)
{
	// add snake links horizontally to the left [ ---* ]
	const auto startPos = settings.startPosition;
	for (uint32 i = 0; i < settings.defaultSize; ++i)
	{
		m_links.AddTail(Position{startPos.x - i, startPos.y});
	}
}

void Snake::move(const Input& input)
{
	// can't move opposite direction
	if (!m_lastInput.opposite(input))
	{
		m_lastInput = input;
	}
	m_links.MoveTail(m_links.GetTail(), m_links.GetHead(), m_links.GetHead()->GetValue());
	m_links.GetHead()->GetValue() += Position(m_lastInput.x, m_lastInput.y);
}

void Snake::increaseTail()
{
	m_links.AddTail(m_links.GetTail()->GetValue());
}
