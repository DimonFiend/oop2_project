#include "GamePanelUI.h"
#include "Settings.h"

GamePanelUI::GamePanelUI() : UIElement(sf::Vector2f(0, 0))
{
	m_topPanel = std::make_unique<PanelUI>(sf::Vector2f(Settings::Instance().getWidth(), 100), sf::Vector2f(0, 0));
	m_bottomPanel = std::make_unique<PanelUI>(sf::Vector2f(Settings::Instance().getWidth(), 125), sf::Vector2f(0, 775));

}

void GamePanelUI::draw(sf::RenderWindow& window)
{
	m_topPanel->draw(window);
	m_bottomPanel->draw(window);
}