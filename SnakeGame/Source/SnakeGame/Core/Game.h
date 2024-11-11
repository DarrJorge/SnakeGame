// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types.h"

namespace SnakeGame
{
	class Grid;
	class Snake;
	class Food;
	
	class Game
	{
	public:
		Game(const Settings& settings);
		
		/**
		 * Return the pointer to the grid object
		 * @return TSharedPtr<Grid> pointer to the grid object
		 */
		TSharedPtr<Grid> getGrid() const { return m_grid; }

		/**
		 * Return the pointer to the Snake object
		 * @return TSharedPtr<Snake> pointer to the snake object
		 */
		TSharedPtr<Snake> getSnake() const { return m_snake; }

		/**
		 * Return the pointer to the Food object
		 * @return TSharedPtr<Food> pointer to the food object
		*/
		TSharedPtr<Food> getFood() const { return m_food; }

		void update(float deltaSeconds, const Input& input);

	private:
		const Settings c_settings;
		TSharedPtr<Grid> m_grid;
		TSharedPtr<Snake> m_snake;
		TSharedPtr<Food> m_food;

		uint32 m_score{0};

		float m_moveSeconds{0.0f};
		bool m_gameOver{false};

		void move(const Input& input);
		void updateGrid();
		bool updateTime(float deltaSeconds);
		bool died() const;
		void generateFood();
		bool foodTaken() const;
	};
}
