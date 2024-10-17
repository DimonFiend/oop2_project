#pragma once
#include "UIElement.h"
#include "PanelUI.h"

class GamePanelUI : public UIElement{
public:
	GamePanelUI();
	void draw(sf::RenderWindow& window) override;
	bool checkContain(const sf::Vector2f& point) const { return false; };
private:
	std::unique_ptr<PanelUI> m_topPanel;
	std::unique_ptr<PanelUI> m_bottomPanel;
};