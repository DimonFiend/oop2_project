#include "PlayerStatusBarUI.h"
#include "macros.h"
#include "Resources.h"

PlayerStatusBarUI::PlayerStatusBarUI(Player& player, const sf::Vector2f& pos)
	:m_maxHealth(Macros::PLAYER_MAX_HP),
	m_currentHealth(player.getHealth())
{
	setPosition(pos);
	setBackground();
	setText(player.getName());
	setHealthBar();
	setPlayerHpBar();
	setHealthText();
}

void PlayerStatusBarUI::setText(const std::string& name)
{
	m_Pname.setFont(Resources::Instance().getFont());
	m_Pname.setString(name);
	m_Pname.setCharacterSize(20);
	m_Pname.setFillColor(sf::Color::Red);

	auto panelSize = m_background.getSize();
	auto panelPos = m_background.getPosition();
	m_Pname.setPosition({panelPos.x - panelSize.x / 2 + 10, panelPos.y - panelSize.y / 2});
}

void PlayerStatusBarUI::setHealthText()
{
	m_healthText.setFont(Resources::Instance().getFont());
	m_healthText.setString(std::to_string(m_currentHealth) + " / " + std::to_string(m_maxHealth));
	m_healthText.setCharacterSize(17);
	m_healthText.setFillColor(sf::Color::Red);

	auto textBounds = m_healthText.getLocalBounds();
	m_healthText.setOrigin(textBounds.width / 2, textBounds.height / 2 + 5);
	m_healthText.setPosition(m_HP_backgroundBar.getPosition()); 
}

void PlayerStatusBarUI::setHealthBar()
{
	m_HP_backgroundBar.setSize({ m_background.getSize().x - 20 , 20});
	auto Size = m_HP_backgroundBar.getSize();
	m_HP_backgroundBar.setOrigin({ Size.x / 2, Size.y / 2 });
	m_HP_backgroundBar.setFillColor(sf::Color::White);
	m_HP_backgroundBar.setOutlineColor(sf::Color::Black);
	m_HP_backgroundBar.setOutlineThickness(2);
	auto Pos = m_background.getPosition();
	m_HP_backgroundBar.setPosition({ Pos.x  , Pos.y + 10 });
}

void PlayerStatusBarUI::setPlayerHpBar()
{
	m_HP_foregroundBar.setSize(m_HP_backgroundBar.getSize());
	auto Size = m_HP_foregroundBar.getSize();
	m_HP_foregroundBar.setOrigin({ Size.x / 2, Size.y / 2 });
	m_HP_foregroundBar.setPosition(m_HP_backgroundBar.getPosition());
	m_HP_foregroundBar.setFillColor(sf::Color::Green);
	updatePlayerHp();
}

void PlayerStatusBarUI::updatePlayerHp()
{
	float healthPrecentage = float(m_currentHealth) / float(m_maxHealth);
	sf::Vector2f updatedSize = { m_HP_backgroundBar.getSize().x * healthPrecentage ,
		                         m_HP_backgroundBar.getSize().y };
	m_HP_foregroundBar.setSize(updatedSize);
	m_healthText.setString(std::to_string(m_currentHealth) + " / " + std::to_string(m_maxHealth));
}

void PlayerStatusBarUI::setBackground()
{
	m_background.setSize({ 150, 55 });
	m_background.setFillColor(sf::Color(0, 0, 139, 160));
	m_background.setOutlineColor(sf::Color(173, 216, 230));
	m_background.setOrigin(m_background.getSize().x / 2, m_background.getSize().y / 2);
	m_background.setPosition(getPosition());
}

void PlayerStatusBarUI::draw(sf::RenderWindow& window)
{
	updatePlayerHp();
	window.draw(m_background);
	window.draw(m_Pname);
	window.draw(m_HP_backgroundBar);
	window.draw(m_HP_foregroundBar);
	window.draw(m_healthText);
}
