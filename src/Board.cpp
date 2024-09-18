#include "Board.h"
#include "Tile.h"
#include "ObjFactory.h"
#include "Resources.h"
#include <string>
#include "Settings.h"

const int TILES_COUNT = 8;
const float TILES_SIZE = 80;

Board::Board() : m_tilesCount(TILES_COUNT), m_tileSize(TILES_SIZE) {
	// Initialize the board with tiles
	float startX= Settings::Instance().getWidth() / 1.5f;
	float startY = Settings::Instance().getHeight() / 8;

	for (int i = 0; i < m_tilesCount; i++) 
	{
		float posY = startY + i * m_tileSize;
		for (int j = 0; j < m_tilesCount; j++)
		{
			float posX =startX + j * m_tileSize;

			std::unique_ptr<Tile> tile;
			sf::Vector2f size{ m_tileSize, m_tileSize };
			if ((i + j) % 2 == 0)
			{
				tile = std::move(ObjFactory::create("Tile", "BrightTile", size));
			}
			else
			{
				tile = std::move(ObjFactory::create("Tile", "BlueTile", size));
			}
			sf::Vector2f pos{ posX, posY };
			tile->setPosition(pos);
			m_tiles.push_back(std::move(tile));
		}
	}
}

void Board::draw(sf::RenderWindow& window) {
	// Render all tiles on the board
	for (auto& tile : m_tiles) {
		tile->draw(window);	
	}
}