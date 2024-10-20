#pragma once
#include "UnitState/UnitState.h"

#include <SFML/Graphics.hpp>

class MoveState : public UnitState
{
public:
	MoveState(sf::Sprite& sprite, const float speed) : m_sprite(sprite), m_speed(speed) {};
	virtual std::unique_ptr<MoveState> clone(sf::Sprite& sprite) const = 0;

protected:

	sf::Sprite& m_sprite;
	const float m_speed;
};