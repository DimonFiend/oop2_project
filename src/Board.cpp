#include "Board.h"
#include "Tile.h"
#include "ObjFactory.h"
#include "Resources.h"
#include <string>
#include "Settings.h"

const int TILES_COUNT = 8;
const float TILES_SIZE = 100;

Board::Board() : m_tilesCount(TILES_COUNT), m_tileSize(TILES_SIZE) {
	// Initialize the board with tiles
	float startX= Settings::Instance().getWidth() / 1.5f;
	float startY = Settings::Instance().getHeight() / 9;

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
			sf::Vector2f pos{ posX + m_tileSize / 2.f , posY + m_tileSize / 2.f };
			tile->setPosition(pos);
			m_tiles.push_back(std::make_pair(std::move(tile), nullptr));
		}
	}
}

void Board::draw(sf::RenderWindow& window) {
	// Render all tiles on the board
	for (auto& tile : m_tiles) {
		tile.first->draw(window);
	}

	for (auto& tile : m_tiles) {
		if (tile.second) {
			tile.second->draw(window);
		}
	}
}

bool Board::placeOnBoard(SlotPair* tile)
{
	for(auto& t : m_tiles)
	{
		if(t.first->checkContain(tile->second->getPosition()))
		{
			tile->second->setInitPos(t.first->getPosition());
			tile->second->setPosition(t.first->getPosition());
			t.second = std::move(tile->second);
			return true;
		}
	}
	return false;
}
