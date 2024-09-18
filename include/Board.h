#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Board {
public:
    // Constructor initializes the board with tiles
    Board();

    // Render all tiles on the board
    void draw(sf::RenderWindow& window);
private:
    sf::View m_view;
    std::vector<std::unique_ptr<GameObject>> m_tiles; // Vector of tiles to represent the board
    sf::Vector2f m_boardSize; // Number of tiles in each row and column
    const int m_tilesCount; // Number of tiles in each row and column
    const float m_tileSize; // Size of each tile
};