#include "Tile.h"
#include "Resources.h"
#include "ObjFactory.h"

bool Tile::m_bool_init = ObjFactory::registerit("Tile", [](const std::string& type, sf::Vector2f& size) -> std::unique_ptr<Tile> { return std::make_unique<Tile>(type, size); });

Tile::Tile(const std::string& type, sf::Vector2f size)
{
    getSprite().setTexture(Resources::Instance().getTexture(type));

    auto textureBounds = getSprite().getLocalBounds().getSize();
    // Calculate the scale factor to fit the sprite into m_tileSize
    sf::Vector2f scale_factor = {
        size.x / textureBounds.x,
        size.y / textureBounds.y
    };

    getSprite().setScale(scale_factor);
    // Resize the sprite to match m_tileSize
    auto spriteSize = getSprite().getGlobalBounds().getSize();
    // Set the origin to the middle of the sprite
    sf::Vector2f origin = spriteSize / 2.f;
    getSprite().setOrigin(origin);
    // Set the sprite's position
}