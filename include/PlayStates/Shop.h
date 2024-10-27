#pragma once
#include "ShopUI.h"
#include <map>
#include <array>

class BuyingStateUnit;
class Player;
class Shop {
public:
    Shop(const sf::Vector2f& position);
    void draw(sf::RenderWindow& window);
    void setVisible(bool visible);
    void handleClick(sf::Vector2f mousePos, Player* player);
    void update(const float dtTime = 0);
private:
    ShopUI m_shopUI;
    std::map<int, std::string> m_hero;
    std::array<std::unique_ptr<BuyingStateUnit>, 8> m_heroesShop;
    bool m_visible;

    void generateHeroes();
};