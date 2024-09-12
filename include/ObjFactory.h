#pragma once
#include <iostream>
#include <memory>
#include <map>
#include "GameObject.h"
typedef std::map<std::string, std::unique_ptr<GameObject>(*)()> mymap;

// ================   class Factory   ============================
class ObjFactory {
public:
	static std::unique_ptr<GameObject> create(const std::string& name);
	static bool registerit(const std::string& name, std::unique_ptr<GameObject>(*)());

private:
	static mymap& getMap()
	{
		static mymap m_map;
		return m_map;
	}
};

std::unique_ptr<GameObject> ObjFactory::create(const std::string& name) {
	auto it = getMap().find(name);
	if (it == getMap().end())
		return nullptr;
	return it->second();
}

bool ObjFactory::registerit(const std::string& name, std::unique_ptr<GameObject>(*f)()) {
	getMap().emplace(name, f);
	return true;
}