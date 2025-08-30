#pragma once
#include "UIElement.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <vector>

class ShopUI : public UIElement {
public:
    ShopUI(const sf::Vector2f& position);
    void draw(sf::RenderWindow& window) override;
    const sf::Vector2f& operator[](int index) const;
    bool checkContain(const sf::Vector2f& point) const;
    bool checkExpandButton(const sf::Vector2f& point) const;
private:
    void setFrame(const sf::Vector2f pos);
    void setExpandButton();
    sf::RectangleShape m_frame;
    sf::RectangleShape m_expandButton;
    sf::Text m_expandButtonText;
    std::vector<std::unique_ptr<Tile>> m_slots;
    int m_numSlots;
};