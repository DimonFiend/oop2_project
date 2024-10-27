#include "SorcererAttributes.h"
#include "HeroFactory.h"
#include "Resources.h"
#include "UnitState/MoveToClosest.h"

SorcererAttributes::SorcererAttributes()
{
	setAttack(5);
	setHealth(40);
	setSpeed(3);
	setCost(0);
	setAttackRange(2);
	setName("Sorcerer");
    m_moveState = std::make_unique<MoveToClosest>(getSpeed());
}

bool SorcererAttributes::m_bool_init = HeroFactory::registerit("Sorcerer",
	[]() -> std::unique_ptr<UnitsAttributes> {
		return std::make_unique<SorcererAttributes>(); });

static AnimationData SorcererAnimation()
{
    const auto size = sf::Vector2i(80, 80);
    const auto initSpace = sf::Vector2i(0, 0);
    const auto middleSpace = sf::Vector2i(80, 0);

    auto sorcerer = AnimationData{};
    auto currentStart = initSpace;

    auto nextStart = [&](){return currentStart += middleSpace;};

    sorcerer.m_data[CharacterActions::Idle].emplace_back(currentStart, size);
    sorcerer.m_data[CharacterActions::Idle].emplace_back(nextStart(), size);
    sorcerer.m_data[CharacterActions::Idle].emplace_back(nextStart(), size);
    sorcerer.m_data[CharacterActions::Idle].emplace_back(nextStart(), size);

    sorcerer.m_data[CharacterActions::Walk].emplace_back(nextStart(), size);
    sorcerer.m_data[CharacterActions::Walk].emplace_back(nextStart(), size);
    sorcerer.m_data[CharacterActions::Walk].emplace_back(nextStart(), size);
    sorcerer.m_data[CharacterActions::Walk].emplace_back(nextStart(), size);
    return sorcerer;
}

static bool reg_animation = Resources::registerAnimation("Sorcerer", SorcererAnimation());