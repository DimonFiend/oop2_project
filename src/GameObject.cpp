#include "GameObject.h"
#include "Resources.h"
#include <iostream>
GameObject::GameObject(const std::string& type, sf::Vector2f& pos)
{
	m_sprite.setTexture(Resources::Instance().getTexture(type));
	sf::Vector2f origin = { m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2 };
	m_sprite.setOrigin(origin);
	m_sprite.setPosition({pos.x + origin.x, pos.y + origin.y});

}