#include "BoardUI.h"
#include "Settings.h"
#include "macros.h"
#include <iostream>
BoardUI::BoardUI(const sf::Vector2f& pos) : UIElement(pos) 
{
	auto pos_offset = sf::Vector2f{ Macros::BOARD_TILE_SIZE.x / 2, Macros::BOARD_TILE_SIZE.y / 2 };
	for (int i = 0; i < Macros::BOARD_SIZE; i++)
	{
		float posY = pos.y + i * Macros::BOARD_TILE_SIZE.y;
		for (int j = 0; j < Macros::BOARD_SIZE; j++)
		{
			float posX = pos.x + j * Macros::BOARD_TILE_SIZE.x;

			std::unique_ptr<Tile> tile{ nullptr };

			if ((i + j) % 2 == 0)
			{
				tile = std::make_unique<Tile>("BrightTile", Macros::BOARD_TILE_SIZE);
			}
			else
			{
				tile = std::make_unique<Tile>("BlueTile", Macros::BOARD_TILE_SIZE);
			}

			tile->setPosition({ posX + pos_offset.x, posY + pos_offset.y});
			m_tiles[i][j] = std::move(tile);
		}
	}

	setBounds();
}

void BoardUI::setBounds()
{
	auto width = Macros::BOARD_SIZE * Macros::BOARD_TILE_SIZE.x;
	auto height = Macros::BOARD_SIZE * Macros::BOARD_TILE_SIZE.y;
	m_bounds = sf::FloatRect{ getPosition(), sf::Vector2f{ width, height} };
	m_userBound = sf::FloatRect{ getPosition(), sf::Vector2f{ Macros::BOARD_TILE_SIZE.x * 3, height } };
}

void BoardUI::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < m_tiles.size(); i++)
	{
		for (int j = 0; j < m_tiles[i].size(); j++)
		{
			m_tiles[i][j]->draw(window);
		}
	}
}

sf::Vector2i BoardUI::posToIndex(const sf::Vector2f& pos)
{
	int indexX = std::floor((pos.x - getPosition().x) / Macros::BOARD_TILE_SIZE.x);
	int indexY = std::floor((pos.y - getPosition().y) / Macros::BOARD_TILE_SIZE.y);

	if (indexX >= 0 && indexX < Macros::BOARD_SIZE && indexY >= 0 && indexY < Macros::BOARD_SIZE)
	{
		return sf::Vector2i{ indexX, indexY };
	}

	return sf::Vector2i(-1,-1);
}

sf::Vector2f BoardUI::indexToPos(const sf::Vector2i& index)
{
	return m_tiles[index.y][index.x]->getPosition();
}

bool BoardUI::checkContain(const sf::Vector2f& point) const
{
	return m_userBound.contains(point);
}

sf::Vector2f BoardUI::getRandomePlacableSlot()
{
	return indexToPos({(rand() % 3),(rand() % 8)});
}

