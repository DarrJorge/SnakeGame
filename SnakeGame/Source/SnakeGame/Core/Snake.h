#pragma once
#include "Types.h"

namespace SnakeGame
{
	class Snake
	{
	public:
		Snake(const Settings::Snake& settings);

		const TSnakeList& links() const { return m_links; }
		const Position head() const { return m_links.GetHead()->GetValue(); }
		const TPositionPtr* body() const { return m_links.GetHead()->GetNextNode(); }

		void move(const Input& input);

	private:
		TSnakeList m_links;
		Input m_lastInput{1,0};
	
	};
}
