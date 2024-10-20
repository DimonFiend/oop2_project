#include "CombatState.h"
#include "Player.h"
#include <iostream>


CombatState::CombatState(Player& player1, Player& player2)
{
	initPlayers(player1, m_player1);
	initPlayers(player2, m_player2);

	// mirror second players units
	for (auto& i : m_player2)
	{
		i.setIndex(i.getInverseIndex());
		i.setPosition(m_board.indexToPos(i.getIndex()));
	}
}

void CombatState::update()
{

}

void CombatState::draw(sf::RenderWindow& window)
{
	for (auto& i : m_player2)
	{
		i.draw(window);
	}
	for (auto& i : m_player1)
	{
		i.draw(window);
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
