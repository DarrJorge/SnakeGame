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
	m_links.RemoveNode(m_links.GetTail());
	m_links.InsertNode(m_links.GetHead()->GetValue(), m_links.GetHead()->GetNextNode());
	m_links.GetHead()->GetValue() += Position(input.x, input.y);
}