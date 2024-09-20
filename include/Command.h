#pragma once
#include <SFML/Graphics.hpp>


class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;  
};

class NewGame : public Command {
public:
    NewGame(sf::RenderWindow& window) :m_window(window) {};
    void execute() override;  
private:
    sf::RenderWindow &m_window;
    
};

class Settings : public Command {
public:
    void execute() override;
};

class Tutorial : public Command {
public:
    void execute() override;
};

