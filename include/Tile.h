#pragma once

#include "GameObject.h"
#include "ObjFactory.h"

class Tile : public GameObject {
public:
	Tile() = default;

        // Render the tile on the window
    virtual void draw(sf::RenderWindow& window) { window.draw(GameObject::getSprite()); };
    static sf::Vector2f getSize() { static sf::Vector2f size{ m_tileWidth, m_tileHeight }; return size; };

private:
   static bool m_bool_init;
   static const int m_tileWidth = 64; // Width of the tile
   static const int m_tileHeight = 64;
};

bool Tile::m_bool_init = ObjFactory::registerit("Tile", []() -> std::unique_ptr<GameObject> { return std::make_unique<Tile>(); });