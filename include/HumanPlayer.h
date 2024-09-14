#pragma once

#include "Player.h"

class HumanPlayer : public Player
{

public:
	HumanPlayer() = default;
	virtual ~HumanPlayer() = default;

	virtual void draw(sf::RenderWindow& window) {};
	virtual void update() {};
};