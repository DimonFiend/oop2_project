#include "Heroes.h"
#include "HeroFactory.h"
#include "Resources.h"

bool Heroes::m_bool_init = HeroFactory::registerit("Heroes",
	[](const std::string& name, sf::Vector2f& pos) -> std::unique_ptr<Heroes> {
		return std::make_unique<Heroes>(name, pos); });


Heroes::Heroes(const std::string& name, sf::Vector2f& pos)
{
	getSprite().setTexture(Resources::Instance().getTexture("Davis"));
	getSprite().setTextureRect(sf::IntRect(0, 0, 80, 80));
	auto size = getSprite().getTextureRect().getSize();
	getSprite().setOrigin(size.x / 2, size.y / 2);
	getSprite().setPosition(pos);
	switch (name[0])
	{
	case 'a':
		getSprite().setColor(sf::Color::Red);
		break;
	case 'b':
		getSprite().setColor(sf::Color::Green);
		break;
	case 'c':
		getSprite().setColor(sf::Color::Blue);
		break;
	}
}