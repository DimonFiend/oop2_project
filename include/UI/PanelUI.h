#pragma once

#include "UIElement.h"

class PanelUI : public UIElement {
public:
	PanelUI(const sf::Vector2f size,const sf::Vector2f& pos);
	void draw(sf::RenderWindow& window) override;
	bool checkContain(const sf::Vector2f& point) const { return false;};
private:
	sf::Sprite m_panel;

};