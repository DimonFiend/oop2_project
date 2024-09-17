#pragma once
#include <SFML/Graphics.hpp>

class GameObject 
{
public:
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual ~GameObject() = default;
	GameObject(const std::string& type, sf::Vector2f& pos);

protected:
	sf::Sprite getSprite() { return m_sprite; };

private:
	sf::Sprite m_sprite;
};