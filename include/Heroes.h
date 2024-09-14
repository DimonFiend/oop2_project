#pragma once

#include "Creatures.h"

class Heroes : public Creatures {
public:
	Heroes() = default;
	void draw(sf::RenderWindow& window) override {};
};