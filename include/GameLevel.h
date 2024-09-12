#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>

class GameLevel {
	Board m_board;
	void draw(sf::RenderWindow& window) {
		m_board.draw(window);
	}

public:
	GameLevel() = default;
};