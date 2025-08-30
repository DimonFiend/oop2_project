#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
public:
	virtual void draw(sf::RenderWindow& window) { window.draw(m_sprite);};
	virtual ~GameObject() = default;
	bool checkContain(sf::Vector2f point);
	bool checkContain(const sf::Sprite& sprite);
	const sf::Vector2f& getPosition() const;
	virtual void setPosition(sf::Vector2f pos);
	void setInitPos(sf::Vector2f pos) { m_initPos = pos; };
	void initPos() { m_sprite.setPosition(m_initPos); };
protected:
	sf::Sprite& getSprite() { return m_sprite; };
private:
	sf::Sprite m_sprite;
	sf::Vector2f m_initPos;
};