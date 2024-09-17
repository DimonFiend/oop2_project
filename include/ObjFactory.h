#pragma once
#include <iostream>
#include <memory>
#include <map>
#include "GameObject.h"
#include <functional>

// ================   class Factory   ============================
class ObjFactory {
public:
	using objFunction = std::function<std::unique_ptr<GameObject>(const std::string&, sf::Vector2f&)>;
	using mymap = std::map<std::string, objFunction>;

	static std::unique_ptr<GameObject> create(const std::string& name,const std::string& type, sf::Vector2f& pos);
	static bool registerit(const std::string& name, objFunction);

private:
	static mymap& getMap()
	{
		static mymap m_map;
		return m_map;
	}
};