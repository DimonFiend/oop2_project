#include "HeroFactory.h"

std::unique_ptr<Heroes> HeroFactory::createHero(const std::string& name ,const std::string& type, sf::Vector2f& pos)
{
	auto it = getMap().find(name);
	if (it == getMap().end())
		throw std::invalid_argument("Unknown object type");
	return it->second(type, pos);
}

bool HeroFactory::registerit(const std::string& name, objFunction f)
{
	getMap().emplace(name, f);
	return true;
}