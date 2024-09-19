#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <utility>
#include "ObjFactory.h"
#include "Heroes.h"
using SlotPair = std::pair<std::unique_ptr<Tile>, std::unique_ptr<Heroes>>;

class Inventory{
public:
	Inventory();
	~Inventory() = default;

	void draw(sf::RenderWindow& window);
	bool isFull() const;
	void addHero(std::unique_ptr<Heroes> hero);
	SlotPair* checkContain(sf::Vector2f point);
private:
	int m_currCapacity;
	std::vector<std::pair<std::unique_ptr<Tile>, std::unique_ptr<Heroes>>> m_items;
	sf::View m_view;
};