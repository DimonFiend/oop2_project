#pragma once
#include "GameObject.h"
#include "ArenaUnit.h"

class Projectile : public GameObject
{
	bool m_hit;

public:
	Projectile(ArenaUnit& target, const float speed, const int dmg);
	~Projectile() = default;

	virtual void update(float dtTime) = 0;
	bool isHit() const { return m_hit; }
	void setHit() { m_hit = true; }

protected:
	void setScale();
	void checkCollision();
	sf::Vector2f& calcDirection();
	void rotateToTarget();
	ArenaUnit* m_target;
	const float m_speed;
	const int m_dmg;
};