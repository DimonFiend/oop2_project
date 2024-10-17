#include "Menu.h"
#include "Resources.h"
#include "Settings.h"

Menu::Menu(GameEngine& engine, sf::RenderWindow& window) : State(engine), m_window(window)
{
    m_backgroundSprite.setTexture(Resources::Instance().getTexture("background"));

    sf::Vector2f size = sf::Vector2f{float(Settings::Instance().getWidth()),
        float(Settings::Instance().getHeight())};

    auto textureSize = m_backgroundSprite.getTexture()->getSize();
    m_backgroundSprite.setScale(
        size.x / static_cast<float>(textureSize.x),
        size.y / static_cast<float>(textureSize.y)
    );

    InitButtons();
}

void Menu::InitButtons()
{
    sf::Vector2f windowSize = sf::Vector2f{ float(Settings::Instance().getWidth()),
        float(Settings::Instance().getHeight()) };

    // Add buttons to the menu
    addButton("newgame", { windowSize.x / 2, 400 }, std::make_unique<NewGame>(m_engine,m_window));
    addButton("settings", { windowSize.x / 2, 525 }, std::make_unique<SettingsMenu>());
    addButton("tutorial", { windowSize.x / 2, 650 }, std::make_unique<TutorialMenu>());

	float scaleFactor = 0.13f;
    // Scale the buttons
    getButton(0)->setScale(scaleFactor, scaleFactor);
    getButton(1)->setScale(scaleFactor, scaleFactor);
    getButton(2)->setScale(scaleFactor, scaleFactor);

}

void Menu::addButton(const std::string& textureName, const sf::Vector2f& position, std::unique_ptr<Command> command) {
    auto onClick = [cmd = command.get(), this]() {cmd->execute(this);};
    m_buttons.emplace_back(std::make_unique<Button>(textureName, position, onClick), std::move(command));
}


Button* Menu::getButton(size_t index) {
    if (index < m_buttons.size()) {
        return m_buttons[index].first.get(); 
    }
    return nullptr;  
}



void Menu::handleInput(sf::Event event)
{

		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
            for (auto& [button, command] : m_buttons) {
                button->handleClick(mousePos);
            }
        }
}

void Menu::update()
{
    	// Nothing to update
}

void Menu::draw()
{
    m_window.draw(m_backgroundSprite);

    for (auto& button: m_buttons)
    {
        button.first->draw(m_window);
    }
}
