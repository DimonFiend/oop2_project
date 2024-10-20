#include "CombatState.h"
#include "Player.h"

#include <iostream>

CombatState::CombatState(GameController& gameController, sf::RenderWindow& window, GameData& matchData,
						 Player& player1, Player& player2)
	: GameState(gameController), m_matchData(matchData), m_window(window), m_board(*matchData.getBoard())
{
	initPlayers(player1, m_player1);
	initPlayers(player2, m_player2);

	// mirror second players units
	for (auto& i : m_player2)
	{
		sf::Vector2i temp = i.getInverseIndex();
		i.setIndex(temp);
		i.setPosition(m_board.indexToPos(i.getIndex()));
	}
}

void CombatState::update()
{
	for (auto& i : m_player2)
	{
		i.update(1);
	}
	for (auto& i : m_player1)
	{
		i.update(1);
	}
}

void CombatState::draw()
{
	m_board.draw(m_window);
	for (auto& i : m_player2)
	{
		i.draw(m_window);
	}
	for (auto& i : m_player1)
	{
		i.draw(m_window);
	}
}

void CombatState::handleInput(sf::Event event)
{
	// no input in combat, maybe pause or quit to menu?
}

void CombatState::initPlayers(Player& p, std::vector<Unit>& units)
{
	Units& onBoard = p.getFighters();

	for (auto& i : onBoard)
	{
		if (i)
		{
			//Unit copy = ;
			units.push_back(*i.get());
		}
	}
}
