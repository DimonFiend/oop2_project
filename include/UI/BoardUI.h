#pragma once
#include "UIElement.h"
#include "Tile.h"
#include <array>
#include "macros.h"

class BoardUI : public UIElement {
private:
	std::array<std::array<std::unique_ptr<Tile>, Macros::BOARD_SIZE>, Macros::BOARD_SIZE> m_tiles;
	sf::FloatRect m_bounds;
	sf::FloatRect m_userBound;
	void setBounds();
public:
	BoardUI(const sf::Vector2f& pos);
	void draw(sf::RenderWindow& window) override;
	virtual ~BoardUI() = default;
	sf::Vector2i posToIndex(const sf::Vector2f& pos);
	sf::Vector2f indexToPos(const sf::Vector2i& index);
	virtual bool checkContain(const sf::Vector2f& point) const;
	sf::Vector2f getRandomePlacableSlot();
};
