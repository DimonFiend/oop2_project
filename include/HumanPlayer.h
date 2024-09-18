#pragma once

#include "Player.h"
#include "Inventory.h"

class HumanPlayer : public Player
{

public:
	HumanPlayer(const std::string& name) : Player(name) {};
	virtual ~HumanPlayer() = default;
private:

};