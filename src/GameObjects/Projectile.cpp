#include "GameObjects/Projectile.h"
#include <numbers>

Projectile::Projectile(ArenaUnit& target, const float speed, const int dmg)
	:m_target(&target),
	m_speed(speed), m_hit(false), m_dmg(dmg)
{
}
void Projectile::checkCollision()
{
	if (m_target->checkContain(getSprite()))
	{
		m_hit = true;
		m_target->changeHP(-m_dmg);
	}
}

sf::Vector2f& Projectile::calcDirection()
{
	auto& pos2 = m_target->getPosition();
	auto& pos1 = getSprite().getPosition();

	sf::Vector2f vec((pos2.x - pos1.x), (pos2.y - pos1.y));
	float mag = std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));

	vec /= mag;

	return vec;
}

void Projectile::rotateToTarget()
{
	auto pos2 = m_target->getPosition();
	auto pos1 = getSprite().getPosition();
	auto dirVec = pos2 - pos1;

	float mag = std::sqrt(std::pow(dirVec.x, 2) + std::pow(dirVec.y, 2));
	dirVec /= mag;

	sf::Vector2f vec(1, 0);
	float dotProduct = dirVec.x * vec.x + dirVec.y * vec.y;
	float det = vec.x * dirVec.y - vec.y * dirVec.x;
	float angle = std::atan2(det, dotProduct);
	getSprite().rotate(angle * 180 / std::numbers::pi);
}
