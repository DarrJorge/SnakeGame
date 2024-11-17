// Snake Game, Copyright DarrJorge. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types.h"
#include "Utils.h"


namespace SnakeGame
{
	class Grid;
	class Snake;
	class Food;
	class Trap;
	
	class Game
	{
	public:
		Game(const Settings& settings, const IPositionRandomizerPtr& randomizer = MakeShared<PositionRandomizer>());
		
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

		/**
		 * Return the array to pointers to the Trap objects
		 * @return TArray<TSharedPtr<Trap>> pointer to the trap objects
		*/
		TArray<TSharedPtr<Trap>> getTraps() const { return m_traps; }

		void update(float deltaSeconds, const Input& input);
		uint32 getScore() const { return m_score; }
		void subcribeOnGameplayEvent(GameplayEventCallback callback);
		float gameTime() const { return m_gameTime; }

	private:
		const Settings c_settings;
		TSharedPtr<Grid> m_grid;
		TSharedPtr<Snake> m_snake;
		TSharedPtr<Food> m_food;

		TArray<TSharedPtr<Trap>> m_traps;

		uint32 m_score{0};
		uint32 m_lastScoreStep{0};
		float m_gameTime{0.0f};
		bool m_usingTraps{false};

		TArray<GameplayEventCallback> m_gameplayEventCallbacks;

		float m_moveSeconds{0.0f};
		bool m_gameOver{false};

		void gameOver();
		void updateGrid();
		bool updateTime(float deltaSeconds);
		bool died(const Position& prevTailPosition) const;
		void generateFood();
		bool foodTaken() const;
		void dispatchEvent(GameplayEvent event);
		void generateTraps();
		bool canSpawnTrap() const;
	};
}
