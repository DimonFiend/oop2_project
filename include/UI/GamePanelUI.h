#pragma once
#include "UIElement.h"
#include "PanelUI.h"
#include "Player.h"

class GamePanelUI : public UIElement{
public:
	GamePanelUI(Player& player);
	void draw(sf::RenderWindow& window) override;
	bool checkContain(const sf::Vector2f& point) const { (void)point; return false; };
private:
	std::unique_ptr<PanelUI> m_topPanel;
	std::unique_ptr<PanelUI> m_bottomPanel;
	const unsigned int& m_playerMoney;
	const int& m_playerBoardCap;
	const int& m_playerMaxBoardCap;
	sf::Sprite m_coinSprite;
	sf::Text m_coinAmount;
	sf::Text m_boardCap;

	void setCapacityUI();
	void updateText();
	void setMoneyUI();
};