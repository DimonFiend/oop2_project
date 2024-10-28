#include "ArenaState.h"
#include <algorithm>
#include <random>

ArenaState::ArenaState(GameController& gameController, sf::RenderWindow& window, GameData& matchData)
	: GameState(gameController), m_window(window), m_board(*matchData.getBoard())
{
	setPlayersCombat(matchData);
}

void ArenaState::setPlayersCombat(GameData& matchData)
{
	auto& computers = matchData.getComputerPlayers();
	std::vector<int> indexes(computers.size());
	for (int i{ 0 }; auto & index:indexes) { index = i; i++; }
	std::random_device rd;
	auto rng = std::default_random_engine{rd()};
	std::shuffle(indexes.begin(), indexes.end(), rng);

	m_combats.push_back(std::make_unique<CombatState>(*matchData.getPlayer(), *computers[indexes[0]], m_board));

	for (int i{ 1 }; i < computers.size(); i += 2)
	{
		if (i == computers.size() - 1)
		{
			//case of odd number of players
			//*computer[indexeses[i]] auto win;
		}
		else
		{
			m_combats.push_back(std::make_unique<CombatState>(*computers[indexes[i]], *computers[indexes[i+1]], m_board));
		}
	}
}

void ArenaState::update(const float dt)
{ 
	for (auto& states : m_combats)
	{
		states->update(dt);
	}
}

void ArenaState::draw()
{
	m_board.draw(m_window);

	if (m_combats[0])
	{
		m_combats[0]->draw(m_window);
	}
}

void ArenaState::handleInput(sf::Event event)
{}