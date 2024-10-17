#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include "Button.h"
#include "Command.h"
#include "State.h"

class Menu : public State {
public:
    Menu(GameEngine& engine, sf::RenderWindow& window);
    Button* getButton(size_t index);
    virtual void handleInput(sf::Event event);
    void update();
    void draw();

private:

    void addButton(const std::string& textureName, const sf::Vector2f& position, std::unique_ptr<Command> command);
    void InitButtons();
    sf::RenderWindow& m_window;
    std::vector<std::pair<std::unique_ptr<Button>, std::unique_ptr<Command>>> m_buttons;
    sf::Sprite m_backgroundSprite;
};
