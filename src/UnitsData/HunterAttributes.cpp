#include "HunterAttributes.h"
#include "HeroFactory.h"
#include "UnitState/MoveToClosest.h"
#include "Resources.h"
#include "UnitState/RangedAttack.h"

HunterAttributes::HunterAttributes()
{
	setAttack(10);
	setHealth(60);
	setSpeed(30);
	setCost(2);
	setAttackRange(330);
	setAttackSpeed(1.5);
	setName("Hunter");
	m_moveState = std::make_unique<MoveToClosest>(getSpeed());
	m_attackState = std::make_unique<RangedAttack>(getAttackSpeed(), "Arrow");
}

bool HunterAttributes::m_bool_init = HeroFactory::registerit("Hunter",
	[]() -> std::unique_ptr<UnitsAttributes> {
		return std::make_unique<HunterAttributes>(); });

static AnimationData HunterAnimation()
{
	const auto size = sf::Vector2i(80, 80);
	const auto initSpace = sf::Vector2i(0, 0);
	const auto middleSpace = sf::Vector2i(80, 0);

	auto hunter = AnimationData{};
	auto currentStart = initSpace;

	auto nextStart = [&]() {return currentStart += middleSpace; };

	hunter.m_data[CharacterActions::Idle].emplace_back(currentStart, size);
	hunter.m_data[CharacterActions::Idle].emplace_back(nextStart(), size);
	hunter.m_data[CharacterActions::Idle].emplace_back(nextStart(), size);
	hunter.m_data[CharacterActions::Idle].emplace_back(nextStart(), size);

	hunter.m_data[CharacterActions::Walk].emplace_back(nextStart(), size);
	hunter.m_data[CharacterActions::Walk].emplace_back(nextStart(), size);
	hunter.m_data[CharacterActions::Walk].emplace_back(nextStart(), size);
	hunter.m_data[CharacterActions::Walk].emplace_back(nextStart(), size);

	currentStart = sf::Vector2i(0, 80);
	hunter.m_data[CharacterActions::BaseAttack].emplace_back(currentStart, size);
	hunter.m_data[CharacterActions::BaseAttack].emplace_back(nextStart(), size);
	hunter.m_data[CharacterActions::BaseAttack].emplace_back(nextStart(), size);
	hunter.m_data[CharacterActions::BaseAttack].emplace_back(nextStart(), size);
	hunter.m_data[CharacterActions::BaseAttack].emplace_back(nextStart(), size);

	currentStart = sf::Vector2i(0, 320);
	hunter.m_data[CharacterActions::Death].emplace_back(currentStart, size);
	hunter.m_data[CharacterActions::Death].emplace_back(nextStart(), size);
	hunter.m_data[CharacterActions::Death].emplace_back(nextStart(), size);
	hunter.m_data[CharacterActions::Death].emplace_back(nextStart(), size);
	hunter.m_data[CharacterActions::Death].emplace_back(nextStart(), size);
	return hunter;
}

static bool reg_animation = Resources::registerAnimation("Hunter", HunterAnimation());