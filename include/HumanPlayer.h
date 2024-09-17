#pragma once

#include "Player.h"
#include "Inventory.h"

class HumanPlayer : public Player
{

public:
	HumanPlayer(const std::string& name) : Player(name) {};
	virtual ~HumanPlayer() = default;

	virtual void draw(sf::RenderWindow& window) { m_inventory.draw(window); };
	virtual void update() {};

private:
	Inventory m_inventory;
};