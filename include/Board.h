#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "GameObject.h"

class Board {
public:
    // Constructor initializes the board with tiles
    Board();

    // Render all tiles on the board
    void draw(sf::RenderWindow& window);
private:
    std::vector<std::unique_ptr<GameObject>> m_tiles; // Vector of tiles to represent the board
    int boardSize = 8; // Number of tiles in each row and column
};