#include "Inventory.h"

#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Tile.h"
#include "Settings.h"

constexpr int MAX_SLOTS = 8;
constexpr float SLOT_SIZE = 100;
Inventory::Inventory() : m_currCapacity(0)
{
	float startY = Settings::Instance().getHeight() / 8 - SLOT_SIZE;
	auto slot_size = sf::Vector2f{ SLOT_SIZE, SLOT_SIZE };
	for (int i = 0; i < MAX_SLOTS; i++)
	{
		sf::Vector2f pos{ 0, i* SLOT_SIZE + startY};
		auto slot = ObjFactory::create("Tile", "InventorySlot", slot_size);
		slot->setPosition(pos);
		
		m_items.push_back(std::make_pair(std::move(slot), nullptr));
	}

}

void Inventory::draw(sf::RenderWindow& window)
{

	for (auto& slot : m_items)
	{
		slot.first->draw(window);
		if (slot.second)
		{
			slot.second->draw(window);
		}
	}
}

bool Inventory::isFull() const
{
	return m_currCapacity == MAX_SLOTS;
}

void Inventory::addHero(std::unique_ptr<Heroes> hero)
{
	for (auto& slot : m_items)
	{
		if (!slot.second)
		{
			hero->setPosition(slot.first->getPosition());
			hero->setInitPos(slot.first->getPosition());
			slot.second = std::move(hero);

			m_currCapacity++;
			break;
		}
	}
}

SlotPair* Inventory::checkContain(sf::Vector2f point)
{
	for (auto& slot : m_items)
	{
		if (slot.second)
		{
			if (slot.second->checkContain(point))
			{
				return &slot;
				break;
			}
		}
	}
	return nullptr;
}
