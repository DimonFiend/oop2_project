#pragma once

#include "Player.h"
#include "BoardUI.h"
#include "Shop.h"

class ComputerPlayer : public Player {

	std::unique_ptr<Shop> m_shop;
	BoardUI& m_board;
public:
	ComputerPlayer(const std::string& name, BoardUI& board);
	void setShop(std::unique_ptr<Shop> shop);
	virtual void draw(sf::RenderWindow& window) {};

};