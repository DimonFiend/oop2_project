#include "UIElement.h"
#include "Resources.h"
#include <iostream>

UIElement::UIElement(const sf::Vector2f& pos) : m_position(pos) {}


void UIElement::setPosition(sf::Vector2f position)
{
	m_position = position;
}

sf::Vector2f UIElement::getPosition() const
{
	return m_position;
}