#pragma once
#include "ObjFactory.h"

std::unique_ptr<GameObject> ObjFactory::create(const std::string& name, const std::string& type, sf::Vector2f& pos)
{
	auto it = getMap().find(name);
	if (it == getMap().end())
		return nullptr;
	return it->second(type, pos);
}

bool ObjFactory::registerit(const std::string& name, objFunction f)
{
	getMap().emplace(name, f);
	return true;
}