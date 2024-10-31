#include "GamePanelUI.h"
#include "Settings.h"
#include "Resources.h"

GamePanelUI::GamePanelUI(Player& player) : UIElement(sf::Vector2f(0, 0)),
	m_playerMoney(player.getMoney()), m_playerBoardCap(player.getCurrBoardCap()),
	m_playerMaxBoardCap(player.getBoardCap())
{
	m_topPanel = std::make_unique<PanelUI>(sf::Vector2f(Settings::Instance().getWidth(), 100), sf::Vector2f(0, 0));
	m_bottomPanel = std::make_unique<PanelUI>(sf::Vector2f(Settings::Instance().getWidth(), 125), sf::Vector2f(0, 775));
	setMoneyUI();
	setCapacityUI();
}

void GamePanelUI::setCapacityUI()
{
	auto Size = m_boardCap.getLocalBounds().getSize();
	m_boardCap.setOrigin(Size.x / 2, Size.y / 2);
	m_boardCap.setFont(Resources::Instance().getFont());
	m_boardCap.setCharacterSize(30);
	m_boardCap.setFillColor(sf::Color::Blue);
	m_boardCap.setPosition(m_bottomPanel->getPosition().x + Size.x + 50, m_bottomPanel->getPosition().y + 50);
}

void GamePanelUI::setMoneyUI()
{
	m_coinSprite.setTexture(Resources::Instance().getTexture("Coin"));
	auto Size = m_coinSprite.getLocalBounds().getSize();
	m_coinSprite.setOrigin(Size.x / 2, Size.y / 2);
	m_coinSprite.setPosition({ m_topPanel->getPosition().x + 50, m_topPanel->getPosition().y + 50});

	m_coinAmount.setFont(Resources::Instance().getFont());
	m_coinAmount.setCharacterSize(30);
	m_coinAmount.setFillColor(sf::Color::Blue);
	m_coinAmount.setPosition(m_coinSprite.getPosition().x + 20, m_coinSprite.getPosition().y - 17);
}

void GamePanelUI::updateText()
{
	m_coinAmount.setString(" X " + std::to_string(m_playerMoney));
	m_boardCap.setString("Board Capacity: " + std::to_string(m_playerBoardCap) + " / " + std::to_string(m_playerMaxBoardCap));
}

void GamePanelUI::draw(sf::RenderWindow& window)
{
	updateText();
	m_topPanel->draw(window);
	m_bottomPanel->draw(window);
	window.draw(m_coinSprite);
	window.draw(m_coinAmount);
	window.draw(m_boardCap);
}