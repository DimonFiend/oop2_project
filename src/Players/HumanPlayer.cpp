#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(const std::string& name)
	:Player(name)
{}

void HumanPlayer::draw(sf::RenderWindow& window)
{
	getInventory().draw(window);
}