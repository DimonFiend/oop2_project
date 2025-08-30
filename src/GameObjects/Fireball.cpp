#include "GameObjects/Fireball.h"
#include "Resources.h"
#include "HeroFactory.h"

const sf::Vector2f size{30, 30};
constexpr float speed = 200.f;

Fireball::Fireball(ArenaUnit& target, const sf::Vector2f& pos, int damage)
	: Projectile(target, speed, damage)
{
	getSprite().setTexture(Resources::Instance().getTexture("Fireball"));
	getSprite().setTextureRect(sf::IntRect(20, 50, 160, 80));
	getSprite().setScale(size.x / getSprite().getTextureRect().width, size.y /
								  getSprite().getTextureRect().height);

	auto currSize = getSprite().getTextureRect().getSize();
	getSprite().setOrigin(currSize.x / 2.f, currSize.y / 2.f);
	getSprite().setPosition(pos);
	rotateToTarget();

}

void Fireball::update(float dtTime)
{
	auto& direction = calcDirection();

	direction *= dtTime * m_speed;
	getSprite().move(direction);
	checkCollision();
}

bool Fireball::m_registerit = HeroFactory::registerProjectile("Fireball",
	[](ArenaUnit& target, const sf::Vector2f& pos, int dmg) -> std::unique_ptr<Projectile>
	{
		return std::make_unique<Fireball>(target, pos, dmg);
	});