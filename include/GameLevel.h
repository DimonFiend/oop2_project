#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>
#include "GameState.h"

class GameController;
class GameLevel : public GameState {

	Board m_board;

public:
	GameLevel(GameController& controller) : GameState(controller) {};
	virtual ~GameLevel() = default;
	void draw(sf::RenderWindow& window)
	{
		m_board.draw(window);
	}
	void update()
	{

	}
	void processEvents(sf::RenderWindow& window)
	{
		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
	}
};