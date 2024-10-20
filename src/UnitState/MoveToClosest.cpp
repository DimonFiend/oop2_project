#include "UnitState/MoveToClosest.h"

#include <iostream>

MoveToClosest::MoveToClosest(sf::Sprite& sprite, const float speed)
	: MoveState(sprite, speed) {}

std::unique_ptr<MoveState> MoveToClosest::clone(sf::Sprite& sprite) const
{
	return std::make_unique<MoveToClosest>(sprite, m_speed);
}

void MoveToClosest::update(const float dt)
{
	sf::Vector2f offset(1, 1);
	m_sprite.move(offset);
}

void MoveToClosest::onEnter()
{
}

void MoveToClosest::onExit()
{
}
