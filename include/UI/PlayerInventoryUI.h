#pragma once

#include "UIElement.h"
#include "Tile.h"
#include <vector>

class PlayerInventoryUI : public UIElement {
public:
	PlayerInventoryUI(sf::Vector2f& pos);
	void draw(sf::RenderWindow& window) override;
	const sf::Vector2f& operator[](int index) const; //returns the position of the slot at index
	int posToIndex(const sf::Vector2f& pos) const;
	bool checkContain(const sf::Vector2f& point) const;
private:
	void setSlots();
	std::vector<std::unique_ptr<Tile>> m_slots;
};