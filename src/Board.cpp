#include "Board.h"
#include "Tile.h"
#include "ObjFactory.h"
#include "Resources.h"
#include <string>

Board::Board() : m_tilesCount(8) {
	// Initialize the board with tiles
	for (int i = 0; i < m_tilesCount; i++) 
	{
		float posY = i * Tile::getSize().y;
		for (int j = 0; j < m_tilesCount; j++)
		{
			float posX = j * Tile::getSize().x;

			sf::Vector2f pos{ posX, posY };
			if ((i + j) % 2 == 0)
			{
				m_tiles.push_back(std::move(ObjFactory::create("Tile", "BrightTile", pos)));
			}
			else
			{
				m_tiles.push_back(std::move(ObjFactory::create("Tile", "BlueTile", pos)));
			}
		}
	}

	setSize();
	setView();
}

void Board::draw(sf::RenderWindow& window) {
	// Render all tiles on the board
	window.setView(m_view);
	sf::RectangleShape viewRect(m_view.getSize());
	viewRect.setPosition(m_view.getCenter() - m_view.getSize() / 2.0f);
	viewRect.setFillColor(sf::Color::Blue);
	window.draw(viewRect);
	for (auto& tile : m_tiles) {
		tile->draw(window);	
	}
}

void Board::setSize()
{
	m_boardSize.x = Tile::getSize().x * (m_tilesCount + 1);
	m_boardSize.y = Tile::getSize().y * (m_tilesCount + 1);
}

void Board::setView()
{
	m_view.setSize(m_boardSize);
	m_view.setViewport(sf::FloatRect(0.25f, 0.25f, 0.5, 0.5));
	m_view.setCenter(m_boardSize.x / 2, m_boardSize.y / 2);
}