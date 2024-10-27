#pragma once
#include "SFML/Graphics.hpp"

const float MAX_BAR_SIZE = 50.0f;

class HpBar
{

public:

	HpBar(const sf::Vector2f& pos, const int maxHP);

	void draw(sf::RenderWindow& window);
	void move(sf::Vector2f direction);

	int getHP() const { return m_currHP; };

	void changeHP(const int change);

private:

	const float m_maxHP;
	float       m_currHP;

	sf::RectangleShape m_greenHP;
	sf::RectangleShape m_redHP;

};