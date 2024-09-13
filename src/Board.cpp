#include "Board.h"
#include "Tile.h"
#include "ObjFactory.h"
#include "Resources.h"

Board::Board() : m_tilesCount(8) {
	// Initialize the board with tiles
	for (int i = 0; i < m_tilesCount; i++) 
	{
		float posY = i * Tile::getSize().y;
		for (int j = 0; j < m_tilesCount; j++)
		{
			float posX = j * Tile::getSize().x;
			auto tile = ObjFactory::create("Tile");
			sf::Texture* texture;

			if((i+j) % 2 == 0)
				texture = &Resources::Instance().getTexture(TextureID::T_TILE_BROWN);
			else
				texture = &Resources::Instance().getTexture(TextureID::T_TILE_LIGHT);

			tile->setTexture(texture);
			tile->setPosition(sf::Vector2f{ posX, posY });
			m_tiles.push_back(std::move(tile));
		}
	}
	setSize();
	setView();
}

void Board::draw(sf::RenderWindow& window) {
	// Render all tiles on the board
	window.setView(m_view);
	for (auto& tile : m_tiles) {
		tile->draw(window);	
	}

	sf::Texture texture;
	texture.loadFromFile("Davis.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(16, 6, 77, 80));
	sprite.setPosition({ 100,100 });

	window.draw(sprite);
}

void Board::setSize()
{
	m_boardSize.x = Tile::getSize().x * m_tilesCount;
	m_boardSize.y = Tile::getSize().y * m_tilesCount;
}

void Board::setView()
{
	m_view.setSize(m_boardSize);
	m_view.setViewport(sf::FloatRect(0.25f, 0.25f, 0.5, 0.5));
	m_view.setCenter(m_boardSize.x / 2, m_boardSize.y / 2);
}