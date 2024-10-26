#pragma once
#include "UIElement.h"
#include "Player.h"

class PlayerStatusBarUI : public UIElement {
    int m_maxHealth;
    int& m_currentHealth;
    sf::RectangleShape m_background;
    sf::RectangleShape m_HP_backgroundBar;
    sf::RectangleShape m_HP_foregroundBar;
    sf::Text m_Pname;
    sf::Text m_healthText;

    void setText(const std::string& name);
    void setHealthText();
    void setHealthBar();
    void setBackground();
    void setPlayerHpBar();
    void updatePlayerHp();
public:
    PlayerStatusBarUI(Player& player, const sf::Vector2f& pos);
    void draw(sf::RenderWindow& window);
    virtual bool checkContain(const sf::Vector2f& point) const { (void)point; return false; };
    const sf::Vector2f getSize() const { return m_background.getSize(); };
    bool isDead() const { return m_currentHealth <= 0; };

};
