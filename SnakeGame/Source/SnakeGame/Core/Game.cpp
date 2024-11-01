// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Game.h"
#include "Grid.h"
#include "Snake.h"

DEFINE_LOG_CATEGORY_STATIC(LogSnakeGame, All, All);

using namespace SnakeGame;


Game::Game(const Settings& settings) : c_settings(settings)
{
	m_grid = MakeShared<Grid>(settings.gridSize);
	m_snake = MakeShared<Snake>(settings.snake);

	m_grid->update(m_snake->body(), CellType::Snake);
	m_grid->printDebug();
}

void Game::update(float deltaSeconds, const Input& input)
{
	if (m_gameOver || !updateTime(deltaSeconds)) return;
	
	move(input);
	
	if (died())
	{
		m_gameOver = true;
		UE_LOG(LogSnakeGame, Display, TEXT("------------------ GAME OVER ------------------"));
	}
}

void Game::move(const Input& input)
{
	m_snake->move(input);
	updateGrid();
}

void Game::updateGrid()
{
	m_grid->update(m_snake->body(), CellType::Snake);
	m_grid->printDebug();
}

bool Game::updateTime(float deltaSeconds)
{
	m_moveSeconds += deltaSeconds;
	if (m_moveSeconds < c_settings.gameSpeed) return false;
	m_moveSeconds = 0.0f;
	return true;
}

bool Game::died() const
{
	return m_grid->hitTest(m_snake->head(), CellType::Wall) ||
		m_grid->hitTest(m_snake->head(), CellType::Snake);
}
