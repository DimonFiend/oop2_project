#include "DennisAttributes.h"
#include "HeroFactory.h"
#include "UnitState/MoveToClosest.h"
#include "Resources.h"

DennisAttributes::DennisAttributes()
{
	setAttack(8);
	setHealth(110);
	setSpeed(18);
	setCost(4);
	setAttackRange(1);
	setName("Dennis");
	m_moveState = std::make_unique<MoveToClosest>(getSpeed());
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

    return dennis;
}

static bool reg_animation = Resources::registerAnimation("Dennis", DennisAnimation());