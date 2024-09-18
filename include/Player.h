#pragma once
#include <string.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Inventory.h"

class Player
{

public:
	Player(const std::string& name) : m_lives(100), m_name(name){};
	virtual ~Player() = default;

	void SetName(const std::string name) { m_name = name; };
	const std::string GetName() const { return m_name; };
	virtual void draw(sf::RenderWindow& window) {m_inventory.draw(window);};

	void UpdateLives(int lives) { m_lives -= lives; };
	int GetLives() const { return m_lives;};

	void addHero(std::unique_ptr<Heroes> hero);
	bool hasSpace() const {return !m_inventory.isFull();};

private:
	std::string m_name;
	int m_lives;
	Inventory m_inventory;
};