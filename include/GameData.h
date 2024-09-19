#pragma once
#include <memory>
#include "Player.h"
#include "Board.h"
using SlotPair = std::pair<std::unique_ptr<Tile>, std::unique_ptr<Heroes>>;

class GameData {
public:
	GameData();
	void draw(sf::RenderWindow& window);
	bool checkPurchase(const Heroes* const hero);
	void makePurchase(std::unique_ptr<Heroes> hero);
	SlotPair* checkContain(sf::Vector2f point) {return m_player->checkContain(point);};
	bool placeOnBoard(SlotPair* slot);
private:
	std::unique_ptr<Player> m_player;

	Board m_board;
};