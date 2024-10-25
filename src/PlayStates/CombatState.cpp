#include "CombatState.h"
#include "Player.h"
#include <iostream>
#include "HeroFactory.h"

CombatState::CombatState(Player& player1, Player& player2, BoardUI& board)
	: m_board(board)
{
	initPlayers(player1, m_player1);
	initPlayers(player2, m_player2);

	// mirror second players units
	for (auto& i : m_player2)
	{
		i->setIndex(i->getInverseIndex());
		i->setPos(m_board.indexToPos(i->getIndex()));
	}
}

void CombatState::update()
{
	/*for (auto& i : m_player2)
	{
		i.update(1);
	}
	for (auto& i : m_player1)
	{
		i.update(1);
	}*/
}

void CombatState::draw(sf::RenderWindow& window)
{
	for (auto& i : m_player2)
	{
		i->draw(window);
	}
	for (auto& i : m_player1)
	{
		i->draw(window);
	}
}

void CombatState::handleInput(sf::Event event)
{
	// no input in combat, maybe pause or quit to menu?
}

void CombatState::initPlayers(Player& p, std::vector<std::unique_ptr<ArenaUnit>>& units)
{
	Units& onBoard = p.getFighters();

	for (auto& i : onBoard)
	{
		if (i)
		{
			auto name = i.get()->getName();
			auto index = i.get()->getIndex();
			auto pos = i.get()->getPosition();
			units.push_back(std::move(HeroFactory::createFightStateHero(name, index, pos)));
		}
	}
}
