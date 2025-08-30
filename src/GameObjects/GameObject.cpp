#include "GameObject.h"
#include <iostream>

bool GameObject::checkContain(sf::Vector2f point)
{
	sf::FloatRect rect = m_sprite.getGlobalBounds();
	if (rect.contains(point))
		return true;

	return false;
}

bool GameObject::checkContain(const sf::Sprite& sprite)
{
	if(m_sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
		return true;

	return false;
}

const sf::Vector2f& GameObject::getPosition() const
{
	return m_sprite.getPosition();
}

void GameObject::setPosition(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
}