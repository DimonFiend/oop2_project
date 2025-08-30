#include "CombatState.h"
#include <iostream>
#include "HeroFactory.h"
#include "Resources.h"
#include "Settings.h"
#include <algorithm>

CombatState::CombatState(Player& player1, Player& player2, BoardUI& board)
	: m_board(board), m_player1(player1), m_player2(player2), m_finished(false)
{
	initPlayerOne(m_player1Units);
	initPlayerTwo(m_player2Units);
	setOnEnterText();
}

void CombatState::update(const float dt)
{
	for (auto& i : m_player2Units)
	{
		i->update(dt);
	}
	for (auto& i : m_player1Units)
	{
		i->update(dt);
	}

	processProjectiles(dt);

	if (m_finished) return;

	sort_timer += dt;
	if (sort_timer > sort_interval)
	{
		sort_timer -= sort_interval;
		sortForDrawing();
	}
	
	if (m_textTimer.m_elapsed < m_textTimer.m_totalDuration)
	{
		updateTextOpacity(dt);
	}

	checkForWinner();
}

void CombatState::sortForDrawing()
{
	std::sort(m_player1Units.begin(), m_player1Units.end(), CompareByDistance());
	std::sort(m_player2Units.begin(), m_player2Units.end(), CompareByDistance());
}

void CombatState::checkForWinner()
{
	if(!unitIsAlive(m_player1Units) && unitIsAlive(m_player2Units))
	{
		m_player2.onRoundFinish(5, 0);
		m_player1.onRoundFinish(2, unitCount(m_player2Units) * 4);
		m_finished = true;
	}
	else if (unitIsAlive(m_player1Units) && !unitIsAlive(m_player2Units) * 4)
	{
		m_player1.onRoundFinish(5, 0);
		m_player2.onRoundFinish(2, unitCount(m_player1Units));

		m_finished = true;
	}
	else if (!unitIsAlive(m_player1Units) && !unitIsAlive(m_player2Units) * 4)
	{
		m_player1.onRoundFinish(2,0);
		m_player2.onRoundFinish(2,0);
		m_finished = true;
	}
}

int CombatState::unitCount(const arenaUnits& units)
{
	int count = 0;
	for (auto& i : units)
	{
		if (i->isAlive())
		{
			count++;
		}
	}
	return count;
}

bool CombatState::unitIsAlive(const arenaUnits& units)
{
	for (auto& i : units)
	{
		if (i->isAlive())
		{
			return true;
		}
	}
	return false;
}

void CombatState::draw(sf::RenderWindow& window)
{
	for (auto& i : m_player2Units)
	{
		i->draw(window);
	}
	for (auto& i : m_player1Units)
	{
		i->draw(window);
	}
	for(auto& i : m_projectiles)
	{
		i->draw(window);
	}

	if (m_textTimer.m_elapsed < m_textTimer.m_totalDuration)
	{
		window.draw(m_onEnterText);
	}
}

void CombatState::handleInput(sf::Event event)
{
	// no input in combat, maybe pause or quit to menu?
}

arenaUnits& CombatState::getLeftTeam()
{
	return m_player1Units;
}

arenaUnits& CombatState::getRightTeam()
{
	return m_player2Units;
}

void CombatState::addProjectile(std::unique_ptr<Projectile> projectile)
{
	m_projectiles.push_back(std::move(projectile));
}

void CombatState::initPlayerOne(arenaUnits& units)
{
	Units& onBoard = m_player1.getFighters();

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

void CombatState::initPlayerTwo(arenaUnits& units)
{
	Units& onBoard = m_player2.getFighters();

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

void CombatState::processProjectiles(const float dt)
{
	for (auto& i : m_projectiles)
	{
		i->update(dt);
	}

	std::erase_if(m_projectiles, [](const std::unique_ptr<Projectile>& projectile) { return projectile->isHit(); });
}

void CombatState::setOnEnterText()
{
	m_onEnterText.setFont(Resources::Instance().getFont());
	m_onEnterText.setCharacterSize(55);
	m_onEnterText.setOutlineThickness(3);
	m_onEnterText.setString(m_player1.getName() + " V/S " + m_player2.getName());
	m_onEnterText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	auto size = m_onEnterText.getGlobalBounds().getSize();
	m_onEnterText.setOrigin(size.x / 2, size.y / 2);
	m_onEnterText.setPosition(Settings::Instance().getWidth() / 2, Settings::Instance().getHeight() / 3);
}

void CombatState::updateTextOpacity(float dt)
{
	m_textTimer.m_elapsed += dt;

	if (m_textTimer.m_elapsed < m_textTimer.m_fadeInDuration) {
		// Fade in
		m_textTimer.m_alpha = 255 * (m_textTimer.m_elapsed / m_textTimer.m_fadeInDuration);
	}
	else if (m_textTimer.m_elapsed < m_textTimer.m_fadeInDuration + m_textTimer.m_holdDuration)
	{
		// Hold full visibility
		m_textTimer.m_alpha = 255;
	}
	else
	{
		float calcAlpha = m_textTimer.m_elapsed - m_textTimer.m_fadeInDuration - (m_textTimer.m_holdDuration / m_textTimer.m_fadeOutDuration);
		// Fade out
		m_textTimer.m_alpha = 255 * (1 - calcAlpha);
	}
	

	// Set the text color with updated alpha

	m_onEnterText.setOutlineColor(sf::Color(34, 139, 34, static_cast<sf::Uint8>(m_textTimer.m_alpha)));
	m_onEnterText.setFillColor(sf::Color(54, 69, 79, static_cast<sf::Uint8>(m_textTimer.m_alpha)));

}