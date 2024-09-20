#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
#include "Resources.h"

class Button {
public:
    Button(const std::string& textureName, const sf::Vector2f& position, const std::function<void()>& onClick);

    void draw(sf::RenderWindow& window);
    void handleClick(const sf::Vector2f& mousePosition);
    void setScale(float x, float y);  // New function to scale the button

private:
    sf::Sprite m_sprite;
    std::function<void()> m_onClick;
};

