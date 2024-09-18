#pragma once

#include "Creatures.h"

class Heroes : public Creatures {
private:
	static bool m_bool_init;
	sf::RectangleShape m_hero;
public:
	Heroes(const std::string& name, sf::Vector2f& pos);
	virtual ~Heroes() = default;
	virtual void draw(sf::RenderWindow& window) override;
	bool checkContain(sf::Vector2f point);
	void setPosition(sf::Vector2f pos);
};