#pragma once

#include "Player.h"
#include "BoardUI.h"
#include "Shop.h"

class ComputerPlayer : public Player {

	std::unique_ptr<Shop> m_shop;
	BoardUI& m_board;
public:
	ComputerPlayer(const std::string& name, BoardUI& board);


	//draws the units on the board
	virtual void draw(sf::RenderWindow& window){};
	void update();

};