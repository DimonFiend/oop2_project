#pragma once
#include <memory>
#include "Player.h"
#include "Board.h"

class GameData {
public:
	GameData();
	void draw(sf::RenderWindow& window);
	bool checkPurchase(const Heroes* const hero);
	void makePurchase(std::unique_ptr<Heroes> hero);
private:
	std::unique_ptr<Player> m_player;

	Board m_board;
};