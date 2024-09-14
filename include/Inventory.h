#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class Heroes;
class Tile;
class Inventory{
public:
	Inventory();
	~Inventory() = default;
	void add(std::unique_ptr<Heroes> item);
	void remove(std::unique_ptr<Heroes> item);
	void draw(sf::RenderWindow& window);
	void update();
	void processEvents(sf::RenderWindow& window);

private:
	std::vector<std::pair<Tile , std::unique_ptr<Heroes>>> m_items;
};