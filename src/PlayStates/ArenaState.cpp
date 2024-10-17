#include "ArenaState.h"

ArenaState::ArenaState(GameController& gameController, sf::RenderWindow& window, GameData& matchData)
	: GameState(gameController), m_matchData(matchData), m_window(window), m_board(*matchData.getBoard())
{
}

void ArenaState::update()
{

}

void ArenaState::draw()
{
	m_board.draw(m_window);
}

void ArenaState::handleInput(sf::Event event)
{

}