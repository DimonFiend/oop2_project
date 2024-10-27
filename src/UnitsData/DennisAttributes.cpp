#include "DennisAttributes.h"
#include "HeroFactory.h"
#include "UnitState/MoveToClosest.h"

DennisAttributes::DennisAttributes()
{
	setAttack(8);
	setHealth(110);
	setSpeed(6);
	setCost(4);
	setAttackRange(1);
	setName("Dennis");
	m_moveState = std::make_unique<MoveToClosest>(getSpeed());
}

bool DennisAttributes::m_bool_init = HeroFactory::registerit("Dennis",
	[]() -> std::unique_ptr<UnitsAttributes> {
		return std::make_unique<DennisAttributes>(); });