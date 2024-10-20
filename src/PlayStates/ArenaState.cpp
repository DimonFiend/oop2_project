#include "ArenaState.h"

ArenaState::ArenaState(GameController& gameController, sf::RenderWindow& window, GameData& matchData)
	: GameState(gameController), m_window(window), m_board(*matchData.getBoard())
{
	setPlayersCombat(matchData);
}

void ArenaState::setPlayersCombat(GameData& matchData)
{
	auto& computers = matchData.getComputerPlayers();
	m_combats.push_back(std::make_unique<CombatState>(*matchData.getPlayer(), *computers[0], m_board));
}

void ArenaState::update()
{ 
	//m_combats[0]->update();
}

void ArenaState::draw()
{
	m_board.draw(m_window);
	for (auto& i : m_combats)
	{
		i->draw(m_window);
	}
}

void ArenaState::handleInput(sf::Event event)
{

}