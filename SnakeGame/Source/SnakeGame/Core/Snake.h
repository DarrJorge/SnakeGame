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
		const Position tail() const { return m_links.GetTail()->GetValue(); }

		void move(const Input& input);
		void increaseTail();

	private:
		TSnakeList m_links;
		Input m_lastInput{Input::Default};
	
	};
}
