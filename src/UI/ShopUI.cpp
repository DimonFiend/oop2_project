// ShopUI.cpp
#include "ShopUI.h"
#include "Tile.h"
#include "macros.h"
ShopUI::ShopUI(const sf::Vector2f& position)
    : UIElement(position), m_numSlots(Macros::MAX_SHOP_SLOT)
{
    setFrame(position);

    float frameWidth = m_frame.getSize().x;
    float slotHeight = position.y - m_frame.getSize().y / 2 + 5;
    sf::Vector2f slotSize = { frameWidth / m_numSlots - 10, m_frame.getSize().y - 10};
    for (int i = 0; i < m_numSlots; ++i)
    {
        sf::Vector2f slotPos = { position.x - (frameWidth/2) + 5 + i * (slotSize.x + 10), slotHeight};

        m_slots.push_back(std::make_unique<Tile>("InventorySlot", slotSize));
        m_slots.back()->setPosition({slotPos.x + (slotSize.x / 2.f), slotPos.y + (slotSize.y / 2.f)});  // Center the sprite within the slot
    }
}

void ShopUI::setFrame(const sf::Vector2f pos)
{
    m_frame.setSize({ 1100.f, 200.f });
    m_frame.setOutlineThickness(2.f);
    m_frame.setOutlineColor(sf::Color(0, 0, 0, 255));
    m_frame.setOrigin(m_frame.getSize().x / 2.f, m_frame.getSize().y / 2.f);
    m_frame.setFillColor(sf::Color(255, 255, 255, 111));
    m_frame.setPosition(pos);

}

void ShopUI::draw(sf::RenderWindow& window) {
    window.draw(m_frame);

    for (const auto& slot : m_slots) {
        slot->draw(window);
    }
}

const sf::Vector2f& ShopUI::operator[](int index) const
{
    return m_slots[index]->getPosition();
}

bool ShopUI::checkContain(const sf::Vector2f& point) const
{
    for(const auto& slot : m_slots)
	{
		if(slot->checkContain(point))
		{
			return true;
		}
	}
    return false;
}
