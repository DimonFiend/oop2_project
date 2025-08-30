#include "DennisAttributes.h"
#include "HeroFactory.h"
#include "UnitState/MoveToClosest.h"
#include "Resources.h"
#include "UnitState/MeleeAttack.h"
DennisAttributes::DennisAttributes()
{
	setAttack(20);
	setHealth(110);
	setSpeed(70);
	setCost(4);
	setAttackRange(60);
	setAttackSpeed(2);
	setName("Dennis");
	m_moveState = std::make_unique<MoveToClosest>(getSpeed());
	m_attackState = std::make_unique<MeleeAttack>(getAttackSpeed());
}

bool DennisAttributes::m_bool_init = HeroFactory::registerit("Dennis",
	[]() -> std::unique_ptr<UnitsAttributes> {
		return std::make_unique<DennisAttributes>(); });

static AnimationData DennisAnimation()
{
    const auto size = sf::Vector2i(80, 80);
    const auto initSpace = sf::Vector2i(0, 0);
    const auto middleSpace = sf::Vector2i(80, 0);

    auto dennis = AnimationData{};
    auto currentStart = initSpace;

    auto nextStart = [&]() {return currentStart += middleSpace; };

    dennis.m_data[CharacterActions::Idle].emplace_back(currentStart, size);
    dennis.m_data[CharacterActions::Idle].emplace_back(nextStart(), size);
    dennis.m_data[CharacterActions::Idle].emplace_back(nextStart(), size);
    dennis.m_data[CharacterActions::Idle].emplace_back(nextStart(), size);

	dennis.m_data[CharacterActions::Walk].emplace_back(nextStart(), size);
	dennis.m_data[CharacterActions::Walk].emplace_back(nextStart(), size);
	dennis.m_data[CharacterActions::Walk].emplace_back(nextStart(), size);
	dennis.m_data[CharacterActions::Walk].emplace_back(nextStart(), size);

	currentStart = sf::Vector2i(320, 80);
	dennis.m_data[CharacterActions::BaseAttack].emplace_back(currentStart, size);
	dennis.m_data[CharacterActions::BaseAttack].emplace_back(nextStart(), size);
	dennis.m_data[CharacterActions::BaseAttack].emplace_back(nextStart(), size);
	dennis.m_data[CharacterActions::BaseAttack].emplace_back(nextStart(), size);

	currentStart = sf::Vector2i(0, 320);
	dennis.m_data[CharacterActions::Death].emplace_back(currentStart, size);
	dennis.m_data[CharacterActions::Death].emplace_back(nextStart(), size);
	dennis.m_data[CharacterActions::Death].emplace_back(nextStart(), size);
	dennis.m_data[CharacterActions::Death].emplace_back(nextStart(), size);
	dennis.m_data[CharacterActions::Death].emplace_back(nextStart(), size);
    return dennis;
}

static bool reg_animation = Resources::registerAnimation("Dennis", DennisAnimation());