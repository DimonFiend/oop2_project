#include "Menu.h"
#include "Resources.h"

void Menu::run() {
    sf::RenderWindow window(sf::VideoMode(1920, 1024), "Auto Chess");

    try {
        sf::Texture& backgroundTexture = Resources::Instance().getTexture("background");  
        sf::Sprite backgroundSprite;
        backgroundSprite.setTexture(backgroundTexture);

        backgroundSprite.setScale(
            window.getSize().x / static_cast<float>(backgroundTexture.getSize().x),
            window.getSize().y / static_cast<float>(backgroundTexture.getSize().y)
        );

        // Add buttons to the menu
        addButton("newgame", { 600, 450 }, std::make_unique<NewGame>());
        addButton("settings", { 850, 450 }, std::make_unique<Settings>());
        addButton("tutorial", { 1100, 450 }, std::make_unique<Tutorial>());

        // Scale the buttons
        getButton(0)->setScale(0.2f, 0.2f);
        getButton(1)->setScale(0.2f, 0.2f);
        getButton(2)->setScale(0.19f, 0.19f);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                handleEvent(event, window);
            }

            window.clear();

            window.draw(backgroundSprite);

            draw(window);

            window.display();
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Menu::addButton(const std::string& textureName, const sf::Vector2f& position, std::unique_ptr<Command> command) {
    auto onClick = [cmd = command.get()]() {
        cmd->execute();
        };
    m_buttons.emplace_back(std::make_unique<Button>(textureName, position, onClick), std::move(command));
}

Button* Menu::getButton(size_t index) {
    if (index < m_buttons.size()) {
        return m_buttons[index].first.get(); 
    }
    return nullptr;  
}



void Menu::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
        for (auto& [button, command] : m_buttons) {
            button->handleClick(mousePos);
        }
    }
}

void Menu::draw(sf::RenderWindow& window) {
    for (auto& [button, command] : m_buttons) {
        button->draw(window);
    }
}
