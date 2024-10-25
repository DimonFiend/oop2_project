#pragma once
#include <iostream>
#include <memory>
#include <map>
#include <functional>
#include <SFML/Graphics.hpp>
#include <string>

// ================   class Factory   ============================
class ArenaUnit;
class BuyingStateUnit;
class UnitsAttributes;
class HeroFactory {
public:
	using objFunction = std::function<std::unique_ptr<UnitsAttributes>()>;
	using mymap = std::map<std::string, objFunction>;

	static std::unique_ptr<ArenaUnit> createFightStateHero(const std::string& name, const sf::Vector2i& index, const sf::Vector2f& pos);
	static std::unique_ptr<BuyingStateUnit> createBuyingPhaseHero(const std::string& name, const sf::Vector2f& pos);
	static bool registerit(const std::string& name, objFunction);

private:
	static std::unique_ptr<UnitsAttributes> getAttribute(const std::string& name);
	static mymap& getMap()
	{
		static mymap m_map;
		return m_map;
	}
};