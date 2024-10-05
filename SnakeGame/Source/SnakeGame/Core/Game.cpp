// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Game.h"
#include "Grid.h"

DEFINE_LOG_CATEGORY_STATIC(LogSnakeGame, All, All);

using namespace SnakeGame;


Game::Game(const Settings& settings) : c_settings(settings)
{
	m_grid = MakeShared<Grid>(settings.gridSize);
}
