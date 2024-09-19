#include "Button.h"

Button::Button(const std::string& textureName, const sf::Vector2f& position, const std::function<void()>& onClick)
    : m_onClick(onClick) {
    m_sprite.setTexture(Resources::Instance().getTexture(textureName));
    m_sprite.setPosition(position);
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(m_sprite);
}

void Button::handleClick(const sf::Vector2f& mousePosition) {
    if (m_sprite.getGlobalBounds().contains(mousePosition)) {
        m_onClick();  // Call the callback if clicked
    }
}

// New function to scale the button sprite
void Button::setScale(float x, float y) {
    m_sprite.setScale(x, y);
}
