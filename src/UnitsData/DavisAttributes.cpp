#include "DavisAttributes.h"
#include "HeroFactory.h"

DavisAttributes::DavisAttributes()
{
	setAttack(10);
	setHealth(100);
	setSpeed(5);
	setCost(3);
	setAttackRange(1);
	setName("Davis");
}

bool DavisAttributes::m_bool_init = HeroFactory::registerit("Davis",
	[]() -> std::unique_ptr<UnitsAttributes> {
		return std::make_unique<DavisAttributes>(); });