#include "GameLevel.h"


void GameLevel::draw(sf::RenderWindow& window)
{
	m_board.draw(window);
}

void GameLevel::update()
{

}

void GameLevel::processEvents(sf::RenderWindow& window)
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