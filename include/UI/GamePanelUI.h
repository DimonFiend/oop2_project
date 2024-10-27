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
	unsigned int& m_playerMoney;
	sf::Sprite m_coinSprite;
	sf::Text m_coinAmount;

	void updateText();
	void setMoneyUI();
};