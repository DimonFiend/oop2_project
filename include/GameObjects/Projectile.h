#pragma once
#include "GameObject.h"
#include "ArenaUnit.h"

class Projectile : public GameObject{
public:
	Projectile(ArenaUnit& target);
	//~Projectile() play sound on destruction
	void update(float dtTime);

private:
	bool m_hit;
};