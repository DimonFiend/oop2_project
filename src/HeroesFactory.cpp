#include "HeroFactory.h"
#include "BuyingStateUnit.h"
#include "UnitsAttributes.h"
#include "ArenaUnit.h"

#include "PlayStates/CombatState.h"

#include <random>
#include <iterator>

std::unique_ptr<ArenaUnit> HeroFactory::createFightStateHero(const std::string& name, const sf::Vector2f& pos, CombatState& combat)
{
	return std::make_unique<ArenaUnit>(std::move(getAttribute(name)), pos, combat);
}

std::unique_ptr<BuyingStateUnit> HeroFactory::createBuyingPhaseHero(const sf::Vector2f& pos)
{
	return std::make_unique<BuyingStateUnit>(std::move(getRandomeAttribute()), pos);
}

std::unique_ptr<Projectile> HeroFactory::createProjectile(const std::string& name, ArenaUnit& target, const sf::Vector2f& pos, int dmg)
{
	auto it = getProjectileMap().find(name);
	if (it == getProjectileMap().end())
		throw std::invalid_argument("Unknown object type");

	return getProjectileMap().find(name)->second(target, pos, dmg);
}

bool HeroFactory::registerProjectile(const std::string& name, projectileFnct fnct)
{
	auto result = getProjectileMap().emplace(name, fnct);
	if (result.second) {
		return true;
	}
	else
	{
		throw std::invalid_argument("Registration failed");
	}
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

std::unique_ptr<UnitsAttributes> HeroFactory::getRandomeAttribute()
{
	auto it = getMap().begin();

	// Static random generator initialization for efficiency
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, getMap().size() - 1);

	// Get random index
	int randomIndex = dis(gen);
	std::advance(it, randomIndex);
	return it->second();
}