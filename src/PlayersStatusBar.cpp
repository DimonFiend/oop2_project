#include "PlayersStatusBar.h"
#include <algorithm>

PlayersStatusBar::PlayersStatusBar(GameData& data)
{
	m_playersStatus.push_back(std::make_unique<PlayerStatusBarUI>(*data.getPlayer(),
		                                                           sf::Vector2f{ 1350, 200 }));

	auto pos = m_playersStatus[0]->getPosition();
	auto size = m_playersStatus[0]->getSize();
	auto& computers = data.getComputerPlayers();

	for (int i = 1; i < computers.size() + 1; i++)
	{
		m_playersStatus.push_back(std::make_unique<PlayerStatusBarUI>(*computers[i-1],
			                               sf::Vector2f{ pos.x ,pos.y + (size.y + 10) * i}));
	}
}

void PlayersStatusBar::draw(sf::RenderWindow& window)
{
	for (auto& bars : m_playersStatus)
	{
		bars->draw(window);
	}
}

void PlayersStatusBar::update()
{
	std::erase_if(m_playersStatus,
		[](const std::unique_ptr<PlayerStatusBarUI>& bar) {return bar->isDead(); });
}
