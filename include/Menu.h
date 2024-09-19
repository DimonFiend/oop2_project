#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include<iostream>
#include "Button.h"
#include "Command.h"

class Menu {
public:
    void run();
    void addButton(const std::string& textureName, const sf::Vector2f& position, std::unique_ptr<Command> command);
    Button* getButton(size_t index);
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    std::vector<std::pair<std::unique_ptr<Button>, std::unique_ptr<Command>>> m_buttons;
};

#endif // MENU_H
