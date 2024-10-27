#include "HeroFactory.h"
#include "BuyingStateUnit.h"
#include "UnitsAttributes.h"
#include "ArenaUnit.h"

#include "PlayStates/CombatState.h"

std::unique_ptr<ArenaUnit> HeroFactory::createFightStateHero(const std::string& name, const sf::Vector2f& pos, CombatState& combat)
{
	return std::make_unique<ArenaUnit>(std::move(getAttribute(name)), pos, combat);
}

std::unique_ptr<BuyingStateUnit> HeroFactory::createBuyingPhaseHero(const std::string& name, const sf::Vector2f& pos)
{
	return std::make_unique<BuyingStateUnit>(std::move(getAttribute(name)), pos);
}

bool HeroFactory::registerit(const std::string& name, objFunction f)
{
	
	auto result = getMap().emplace(name, f);
	if (result.second) {
		return true;
	}
	else
	{
		throw std::invalid_argument("Registration failed");
	}
}

std::unique_ptr<UnitsAttributes> HeroFactory::getAttribute(const std::string& name)
{
	auto it = getMap().find(name);
	if (it == getMap().end())
		throw std::invalid_argument("Unknown object type");
	return it->second();
}
