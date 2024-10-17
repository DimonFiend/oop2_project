#pragma once

#include <SFML/Graphics.hpp>

class UIElement {
public:
	UIElement(const sf::Vector2f& pos);
	virtual ~UIElement() = default;
	virtual void draw(sf::RenderWindow& window) = 0;
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition() const;
	virtual bool checkContain(const sf::Vector2f& point) const = 0;

private:
	sf::Vector2f m_position;
};