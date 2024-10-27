#pragma once
#include "UnitState/UnitState.h"

#include <SFML/Graphics.hpp>

class MoveState : public UnitState
{
public:
	MoveState(const float speed) : m_speed(speed) {};

protected:

	const float m_speed;
};