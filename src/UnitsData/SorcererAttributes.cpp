#include "SorcererAttributes.h"
#include "HeroFactory.h"

SorcererAttributes::SorcererAttributes()
{
	setAttack(5);
	setHealth(40);
	setSpeed(3);
	setCost(0);
	setAttackRange(2);
	setName("Sorcerer");
}

bool SorcererAttributes::m_bool_init = HeroFactory::registerit("Sorcerer",
	[]() -> std::unique_ptr<UnitsAttributes> {
		return std::make_unique<SorcererAttributes>(); });