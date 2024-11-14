// Snake Game, Copyright DarrJorge. All Rights Reserved.


#include "Game.h"
#include "Grid.h"
#include "Snake.h"
#include "Food.h"

DEFINE_LOG_CATEGORY_STATIC(LogSnakeGame, All, All);

using namespace SnakeGame;

Game::Game(const Settings& settings, const IPositionRandomizerPtr& randomizer)
	: c_settings(settings)
{
	checkf(settings.gridSize.width / 2 >= settings.snake.defaultSize,
		TEXT("Snake initial length [%i] doesn't for grid width [%i]"),
		settings.snake.defaultSize, settings.gridSize.width);
	
	m_grid = MakeShared<Grid>(settings.gridSize, randomizer);
	m_snake = MakeShared<Snake>(settings.snake);
	m_food = MakeShared<Food>();

	updateGrid();
	generateFood();
}

void Game::update(float deltaSeconds, const Input& input)
{
	if (m_gameOver || !updateTime(deltaSeconds)) return;
	
	m_snake->move(input);
	
	if (died())
	{
		gameOver();
		return;
	}

	if (foodTaken())
	{
		m_score++;
		m_snake->increaseTail();
		dispatchEvent(GameplayEvent::FootTaken);
		generateFood();
	}

	updateGrid();
}

void Game::gameOver()
{
	m_gameOver = true;
	dispatchEvent(GameplayEvent::GameOver);
}

void Game::updateGrid()
{
	m_grid->update(m_snake->links().GetHead(), CellType::Snake);
	//m_grid->printDebug();
}

bool Game::updateTime(float deltaSeconds)
{
	m_gameTime += deltaSeconds;
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

void Game::generateFood()
{
	Position foodPosition;
	if (m_grid->randomEmptyPosition(foodPosition))
	{
		m_food->setPosition(foodPosition);
		m_grid->update(m_food->getPosition(), CellType::Food);
	}
	else
	{
		m_gameOver = true;
		dispatchEvent(GameplayEvent::GameCompleted);
	}
}

bool Game::foodTaken() const
{
	return m_grid->hitTest(m_snake->head(), CellType::Food);
}

void Game::dispatchEvent(GameplayEvent event)
{
	for (const auto& callback : m_gameplayEventCallbacks)
	{
		if (callback)
		{
			callback(event);
		}
	}
}

void Game::subcribeOnGameplayEvent(GameplayEventCallback callback)
{
	m_gameplayEventCallbacks.Add(callback);
}
