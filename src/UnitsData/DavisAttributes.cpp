#include "DavisAttributes.h"
#include "HeroFactory.h"
#include "UnitState/MoveToClosest.h"
#include "Resources.h"
#include "UnitState/MeleeAttack.h"

DavisAttributes::DavisAttributes()
{
	setAttack(10);
	setHealth(70);
	setSpeed(50);
	setCost(3);
	setAttackRange(70);
	setAttackSpeed(3);
	setName("Davis");
	m_moveState = std::make_unique<MoveToClosest>(getSpeed());
	m_attackState = std::make_unique<MeleeAttack>(getAttackSpeed());
}

bool DavisAttributes::m_bool_init = HeroFactory::registerit("Davis",
	[]() -> std::unique_ptr<UnitsAttributes> {
		return std::make_unique<DavisAttributes>(); });

static AnimationData DavisAnimation()
{
    const auto size = sf::Vector2i(80, 80);
    const auto initSpace = sf::Vector2i(0, 0);
    const auto middleSpace = sf::Vector2i(80, 0);

    auto davis = AnimationData{};
    auto currentStart = initSpace;

    auto nextStart = [&]() {return currentStart += middleSpace; };

    davis.m_data[CharacterActions::Idle].emplace_back(currentStart, size);
    davis.m_data[CharacterActions::Idle].emplace_back(nextStart(), size);
    davis.m_data[CharacterActions::Idle].emplace_back(nextStart(), size);
    davis.m_data[CharacterActions::Idle].emplace_back(nextStart(), size);

	davis.m_data[CharacterActions::Walk].emplace_back(nextStart(), size);
	davis.m_data[CharacterActions::Walk].emplace_back(nextStart(), size);
	davis.m_data[CharacterActions::Walk].emplace_back(nextStart(), size);
	davis.m_data[CharacterActions::Walk].emplace_back(nextStart(), size);

	currentStart = sf::Vector2i(320, 80);
	davis.m_data[CharacterActions::BaseAttack].emplace_back(currentStart, size);
	davis.m_data[CharacterActions::BaseAttack].emplace_back(nextStart(), size);
	davis.m_data[CharacterActions::BaseAttack].emplace_back(nextStart(), size);
	davis.m_data[CharacterActions::BaseAttack].emplace_back(nextStart(), size);

	currentStart = sf::Vector2i(0, 320);
	davis.m_data[CharacterActions::Death].emplace_back(currentStart, size);
	davis.m_data[CharacterActions::Death].emplace_back(nextStart(), size);
	davis.m_data[CharacterActions::Death].emplace_back(nextStart(), size);
	davis.m_data[CharacterActions::Death].emplace_back(nextStart(), size);
	davis.m_data[CharacterActions::Death].emplace_back(nextStart(), size);
    return davis;
}

static bool reg_animation = Resources::registerAnimation("Davis", DavisAnimation());