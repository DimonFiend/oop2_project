#include "CombatState.h"
#include "Player.h"
#include <iostream>
#include "HeroFactory.h"

CombatState::CombatState(Player& player1, Player& player2, BoardUI& board)
	: m_board(board)
{
	initPlayerOne(player1, m_player1);
	initPlayerTwo(player2, m_player2);
}

void CombatState::update(const float dt)
{
	for (auto& i : m_player2)
	{
		i->update(dt);
	}
	for (auto& i : m_player1)
	{
		i->update(dt);
	}
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

arenaUnits& CombatState::getLeftTeam()
{
	return m_player1;
}

arenaUnits& CombatState::getRightTeam()
{
	return m_player2;
}

void CombatState::initPlayerOne(Player& p, arenaUnits& units)
{
	Units& onBoard = p.getFighters();

	for (auto& i : onBoard)
	{
		if (i)
		{
			auto name = i.get()->getName();
			auto index = i.get()->getIndex();
			auto pos = i.get()->getPosition();
			units.emplace_back(HeroFactory::createFightStateHero(name, pos, *this));
		}
	}
}

void CombatState::initPlayerTwo(Player& p, arenaUnits& units)
{
	Units& onBoard = p.getFighters();

	for (auto& i : onBoard)
	{
		if (i)
		{
			auto index = i->getInverseIndex();
			auto pos = m_board.indexToPos((index));
			auto name = i.get()->getName();

			units.emplace_back(HeroFactory::createFightStateHero(name, pos, *this));
			units[units.size()-1]->flipUnit();
			units[units.size()-1]->flipTeam();
		}
	}
}
