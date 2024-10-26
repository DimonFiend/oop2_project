#pragma once
#include <memory>
#include <vector>
#include "GameData.h"
#include "PlayerStatusBarUI.h"


class PlayersStatusBar {
	std::vector<std::unique_ptr<PlayerStatusBarUI>> m_playersStatus;


public:
	PlayersStatusBar(GameData& data);
	void draw(sf::RenderWindow& window);
	void update();
};