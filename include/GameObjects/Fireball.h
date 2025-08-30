#pragma once
#include "GameObjects/Projectile.h"

class Fireball : public Projectile
{
public:

	Fireball(ArenaUnit& target, const sf::Vector2f& pos, int damage);

	void update(float dtTime) override;


private:
	static bool m_registerit;
};