#include "ArenaState.h"

ArenaState::ArenaState(GameController& gameController, sf::RenderWindow& window, GameData& matchData)
	: GameState(gameController), m_matchData(matchData), m_window(window), m_board(*matchData.getBoard())
{
	setPlayersCombat();
}

void ArenaState::setPlayersCombat(GameData& matchData)
{
	for (auto& player : m_matchData.getPlayers())
	{
		m_combats.push_back(std::make_unique<CombatState>(m_gameController, m_window, m_matchData, player));
	}
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