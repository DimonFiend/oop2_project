#include "PlayerInventoryUI.h"
#include "Settings.h"
#include "macros.h"
#include <iostream>

PlayerInventoryUI::PlayerInventoryUI(sf::Vector2f& pos) : UIElement(pos)
{
	setSlots();
}

void PlayerInventoryUI::setSlots()
{
	auto slot_size = Macros::INV_SLOT_SIZE;

	for (int i = 0; i < Macros::MAX_INV_SLOT; i++) {
		m_slots.push_back(std::make_unique<Tile>("InventorySlot", slot_size));
		auto pos = sf::Vector2f{ getPosition().x + slot_size.x / 2, getPosition().y + i * slot_size.y + slot_size.y / 2 };
		m_slots[i]->setPosition(pos);
	}
}

void PlayerInventoryUI::draw(sf::RenderWindow& window)
{
	for (auto& slot : m_slots)
	{
		slot->draw(window);
	}
}

const sf::Vector2f& PlayerInventoryUI::operator[](int index) const
{
	if (index < 0 || index >= Macros::MAX_INV_SLOT)
		throw std::out_of_range("Index out of range of player inventory"); // invalid index

	return m_slots[index]->getPosition();
}

int PlayerInventoryUI::posToIndex(const sf::Vector2f& pos) const
{
	int indexY = std::floor((pos.y - getPosition().y) / Macros::INV_SLOT_SIZE.y);

	if (indexY >= 0 && indexY < Macros::BOARD_SIZE)
	{
		return indexY;
	}

	return -1;
}

bool PlayerInventoryUI::checkContain(const sf::Vector2f& point) const
{
	for(auto& slot : m_slots)
	{
		if(slot->checkContain(point))
		{
			return true;
		}
	}

	return false;
}
