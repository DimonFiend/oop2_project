#pragma once

#include "GameObject.h"

class Tile : public GameObject {
public:
    Tile(const std::string& type, sf::Vector2f pos);
        // Render the tile on the window
    virtual void draw(sf::RenderWindow& window) { window.draw(GameObject::getSprite()); };
private:
   static bool m_bool_init;

};