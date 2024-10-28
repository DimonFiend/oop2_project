#include "DavisAttributes.h"
#include "HeroFactory.h"
#include "UnitState/MoveToClosest.h"
#include "Resources.h"

DavisAttributes::DavisAttributes()
{
	setAttack(10);
	setHealth(70);
	setSpeed(15);
	setCost(3);
	setAttackRange(1);
	setName("Davis");
	m_moveState = std::make_unique<MoveToClosest>(getSpeed());
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
    return davis;
}

static bool reg_animation = Resources::registerAnimation("Davis", DavisAnimation());