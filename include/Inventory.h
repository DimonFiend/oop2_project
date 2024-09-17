#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <utility>

#include "Tile.h"
#include "Heroes.h"

class Inventory{
public:
	Inventory();
	~Inventory() = default;

	void draw(sf::RenderWindow& window);

private:
	std::vector<std::pair<std::unique_ptr<GameObject>, std::unique_ptr<Heroes>>> m_items;
	sf::View m_view;
};