// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types.h"

namespace SnakeGame
{
	class Grid;
	
	class Game
	{
	public:
		Game(const Settings& settings);
		TSharedPtr<Grid> getGrid() const { return m_grid; }

	private:
		const Settings c_settings;
		TSharedPtr<Grid> m_grid;
	};
}
