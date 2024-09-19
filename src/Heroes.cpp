#include "Heroes.h"
#include "HeroFactory.h"

bool Heroes::m_bool_init = HeroFactory::registerit("Heroes",
	[](const std::string& name, sf::Vector2f& pos) -> std::unique_ptr<Heroes> {
		return std::make_unique<Heroes>(name, pos); });


Heroes::Heroes(const std::string& name, sf::Vector2f& pos)
{
		m_hero.setSize(sf::Vector2f(50, 50));
	m_hero.setPosition(pos);
	m_hero.setOrigin(m_hero.getSize().x / 2, m_hero.getSize().y / 2);
	switch (name[0])
	{
	case 'a':
		m_hero.setFillColor(sf::Color::Red);
		break;
	case 'b':
		m_hero.setFillColor(sf::Color::Green);
		break;
	case 'c':
		m_hero.setFillColor(sf::Color::Blue);
		break;
	}
}

void Heroes::draw(sf::RenderWindow& window)
{
	window.draw(m_hero);
}

bool Heroes::checkContain(sf::Vector2f point)
{
	sf::FloatRect rect = m_hero.getGlobalBounds();
	if (rect.contains(point))
		return true;
	return false;
}

void Heroes::setPosition(const sf::Vector2f& pos)
{
	m_hero.setPosition(pos);
	std::cout << "Hero POS" << std::endl;
}

void Heroes::setInitPos(const sf::Vector2f& init)
{
	m_initPos = init;
}