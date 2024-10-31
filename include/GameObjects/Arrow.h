#pragma once
#include "GameObjects/Projectile.h"

class Arrow : public Projectile
{
public:

	Arrow(ArenaUnit& target, const sf::Vector2f& pos, int damage);

	void update(float dtTime) override;


private:
	static bool m_registerit;
};