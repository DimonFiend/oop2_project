#pragma once
#include <SFML/Graphics.hpp>

class GameObject 
{
public:
	virtual void draw(sf::RenderWindow& window) = 0;
	GameObject() = default;
	virtual ~GameObject() = default;

	GameObject(const sf::Texture& texture) : m_sprite(texture) {};
	void setTexture(const sf::Texture* texture) { m_sprite.setTexture(*texture); };
	void setPosition(const sf::Vector2f& pos) { m_sprite.setPosition(pos); };
protected:
	sf::Sprite getSprite() { return m_sprite; };
private:
	sf::Sprite m_sprite;

};