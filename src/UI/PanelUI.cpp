#include "PanelUI.h"
#include "Resources.h"

PanelUI::PanelUI(const sf::Vector2f size, const sf::Vector2f& pos) : UIElement(pos)
{
	m_panel.setTexture(Resources::Instance().getTexture("UIPanel"));
	m_panel.setOrigin(m_panel.getLocalBounds().width / 2, m_panel.getLocalBounds().height / 2);
	m_panel.setScale(size.x / m_panel.getGlobalBounds().width, size.y / m_panel.getGlobalBounds().height);
	auto panelSize = m_panel.getGlobalBounds().getSize();
	m_panel.setPosition(pos.x + panelSize.x / 2, pos.y + panelSize.y / 2 );
}

void PanelUI::draw(sf::RenderWindow& window)
{
	window.draw(m_panel);
}