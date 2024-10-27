#include "HpBar.h"

HpBar::HpBar(const sf::Vector2f& pos, const int maxHP)
	: m_maxHP(maxHP), m_currHP(maxHP)
{
	m_greenHP.setSize(sf::Vector2f(MAX_BAR_SIZE, 10.0f));
	m_redHP.setSize(sf::Vector2f(MAX_BAR_SIZE, 10.0f));

	m_greenHP.setFillColor(sf::Color::Green);
	m_redHP.setFillColor(sf::Color::Red);

	m_greenHP.setPosition(pos);
	m_redHP.setPosition(pos);

	m_greenHP.setOutlineColor(sf::Color::White);
	m_redHP.setOutlineColor(sf::Color::White);

	m_greenHP.setOutlineThickness(1.f);
	m_redHP.setOutlineThickness(1.f);
}

void HpBar::draw(sf::RenderWindow& window)
{
	window.draw(m_redHP);
	window.draw(m_greenHP);
}

void HpBar::move(sf::Vector2f direction)
{
	m_greenHP.move(direction);
	m_redHP.move(direction);
}

void HpBar::changeHP(const int change)
{
	m_currHP += change;

	float percent = (m_currHP / m_maxHP) * 100;
	int newSize = (percent/100) * MAX_BAR_SIZE;

	m_greenHP.setSize(sf::Vector2f(newSize, 10.0f));
}
