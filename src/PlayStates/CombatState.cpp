#include "CombatState.h"
#include "Player.h"
#include <iostream>
#include "HeroFactory.h"
#include "Resources.h"
#include "Settings.h"

CombatState::CombatState(Player& player1, Player& player2, BoardUI& board)
	: m_board(board)
{
	initPlayerOne(player1, m_player1);
	initPlayerTwo(player2, m_player2);
	setOnEnterText(player1, player2);
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

	if (m_textTimer.m_elapsed < m_textTimer.m_totalDuration)
	{
		updateTextOpacity(dt);
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

void CombatState::setOnEnterText(const Player& p1, const Player& p2)
{
	m_onEnterText.setFont(Resources::Instance().getFont());
	m_onEnterText.setCharacterSize(55);
	m_onEnterText.setOutlineThickness(3);
	m_onEnterText.setString(p1.getName() + " V/S " + p2.getName());
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