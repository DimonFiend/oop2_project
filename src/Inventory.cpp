#include "Inventory.h"

#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "ObjFactory.h"


constexpr int MAX_SLOTS = 8;

Inventory::Inventory()
{
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		sf::Vector2f pos{ 0, i*Tile::getSize().y};
		m_items.push_back(std::make_pair(std::move(ObjFactory::create("Tile" ,"Slot", pos)), nullptr));
	}
}

void Inventory::draw(sf::RenderWindow& window)
{
	for (auto& slot : m_items)
	{
		slot.first->draw(window);
		if (slot.second) { slot.second->draw(window);}
	}
}