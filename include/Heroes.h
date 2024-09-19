#pragma once

#include "Creatures.h"

class Heroes : public Creatures {
private:
	static bool m_bool_init;
	sf::RectangleShape m_hero;
	sf::Vector2f m_initPos;
public:
	Heroes(const std::string& name, sf::Vector2f& pos);
	virtual ~Heroes() = default;
	virtual void draw(sf::RenderWindow& window) override;
	bool checkContain(sf::Vector2f point);
	void setPosition(const sf::Vector2f& pos);
	void setInitPos(const sf::Vector2f& init);
	void InitPos() { m_hero.setPosition(m_initPos); };
};