#pragma once

#include "GameObject.h"
#include "ObjFactory.h"

class Tile : public GameObject {
public:
    Tile() : GameObject() {};
        // Render the tile on the window
    virtual void draw(sf::RenderWindow& window) { window.draw(GameObject::getSprite()); };
    static sf::Vector2f getSize() {return m_tileSize; };

private:
   static bool m_bool_init;
   static const sf::Vector2f m_tileSize; // Width of the tile

};

bool Tile::m_bool_init = ObjFactory::registerit("Tile", []() -> std::unique_ptr<GameObject> { return std::make_unique<Tile>(); });

const sf::Vector2f Tile::m_tileSize = { 64, 64 };