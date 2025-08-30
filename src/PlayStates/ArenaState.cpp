#include "ArenaState.h"
#include <algorithm>
#include <random>
#include "BuyingState.h"
#include "Menu.h"

ArenaState::ArenaState(GameController& gameController, sf::RenderWindow& window, GameData& matchData)
	: GameState(gameController),
    m_window(window), m_board(*matchData.getBoard()),
    m_matchData(matchData)
{
	setPlayersCombat(m_matchData);
}

void ArenaState::setPlayersCombat(GameData& matchData)
{
    int roundShift = matchData.getRoundCount();
    // Combine human player with computer players in a single vector
    std::vector<Player*> players = {&(*matchData.getPlayer())};

    for (auto& computer : matchData.getComputerPlayers())
    {
        players.push_back(computer.get());
    }

    int numPlayers = players.size();
    m_combats.clear();  // Clear previous combats

    // If odd number of players, add a null player for round-robin
    if (numPlayers % 2 != 0)
    {
        players.push_back(nullptr);
        numPlayers++;
    }

    // Round-robin pairing for the given round
    for (int i = 0; i < numPlayers / 2; ++i)
    {
        int player1Index, player2Index;

        if (i == 0) {
            // Special case: Human player (fixed position) vs rotated opponent
            player1Index = i;
            player2Index = (roundShift % (numPlayers - 1)) + 1;
        }
        else {
            player1Index = (i + roundShift) % (numPlayers - 1) + 1;
            player2Index = (numPlayers - 1 - i + roundShift) % (numPlayers - 1) + 1;
        }

        Player* player1 = players[player1Index];
        Player* player2 = players[player2Index];

        // Only create CombatState if both players are present
        if (player1 && player2)
        {
            m_combats.push_back(std::make_unique<CombatState>(*player1, *player2, m_board));
        }
        else if(player1)
        {
            player1->onRoundFinish(5, 0);
        }
        else
        {
            player2->onRoundFinish(5, 0);
        }
    }
}

bool ArenaState::roundFinished()
{
    for(auto& combat : m_combats)
	{
		if (!combat->isFinished())
		{
			return false;
		}
	}

    m_matchData.nextRound();
    return true;
}


void ArenaState::update(const float dt)
{ 
    m_combats[0]->update(dt);
    for(int i{1}; i < m_combats.size(); i++)
	{
		m_combats[i]->update(dt * 100);
	}

    if(roundFinished())
	{
        m_matchData.clearLosers();
        if (m_matchData.lastOpponent())
        {
            m_game->getEngine().setState(std::make_unique<Menu>(m_game->getEngine(), m_window), true);

        }
        else
        {
            m_game->setState(std::make_unique<BuyingState>(*m_game, m_window, m_matchData), true);

        }
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