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
class CombatState;
class Projectile;

class HeroFactory {
public:
	using objFunction = std::function<std::unique_ptr<UnitsAttributes>()>;
	using projectileFnct = std::function<std::unique_ptr<Projectile>(ArenaUnit& target, const sf::Vector2f& pos, int dmg)>;
	using mymap = std::map<std::string, objFunction>;
	using projectileMap = std::map<std::string, projectileFnct>;

	static bool registerit(const std::string& name, objFunction);
	static std::unique_ptr<ArenaUnit> createFightStateHero(const std::string& name, const sf::Vector2f& pos, CombatState& combat);
	static std::unique_ptr<BuyingStateUnit> createBuyingPhaseHero(const sf::Vector2f& pos);
	static std::unique_ptr<Projectile> createProjectile(const std::string& name, ArenaUnit& target, const sf::Vector2f& pos, int dmg);
	static bool registerProjectile(const std::string& name, projectileFnct);

private:
	static std::unique_ptr<UnitsAttributes> getAttribute(const std::string& name);
	static std::unique_ptr<UnitsAttributes> getRandomeAttribute();

	static mymap& getMap()
	{
		static mymap m_map;
		return m_map;
	}

	static projectileMap& getProjectileMap()
	{
		static projectileMap m_map;
		return m_map;
	}

};