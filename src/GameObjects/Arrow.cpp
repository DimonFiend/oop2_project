#include "GameObjects/Arrow.h"
#include "Resources.h"
#include "HeroFactory.h"

const sf::Vector2f size{ 30, 30 };
constexpr float speed = 200.f;

Arrow::Arrow(ArenaUnit& target, const sf::Vector2f& pos, int damage)
	: Projectile(target, speed, damage)
{

	getSprite().setTexture(Resources::Instance().getTexture("Arrow"));
	getSprite().setTextureRect(sf::IntRect(0, 18, 44, 28));
	getSprite().setScale(size.x / getSprite().getTextureRect().width, size.y /
		getSprite().getTextureRect().height);

	auto currSize = getSprite().getGlobalBounds().getSize();
	getSprite().setOrigin(currSize.x / 2.f, currSize.y / 2.f);
	getSprite().setPosition(pos);
	rotateToTarget();
}

void Arrow::update(float dtTime)
{
	auto& direction = calcDirection();
	direction *= dtTime * m_speed;
	getSprite().move(direction);
	checkCollision();
}

bool Arrow::m_registerit = HeroFactory::registerProjectile("Arrow",
	[](ArenaUnit& target, const sf::Vector2f& pos, int dmg) -> std::unique_ptr<Projectile>
	{
		return std::make_unique<Arrow>(target, pos, dmg);
	});