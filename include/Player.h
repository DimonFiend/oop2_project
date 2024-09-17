#pragma once
#include <string.h>
#include <vector>
#include <SFML/Graphics.hpp>
class Heroes;
class Player
{

public:
	Player(const std::string& name) : m_lives(100), m_name(name){};
	virtual ~Player() = default;

	void SetName(const std::string name) { m_name = name; };
	const std::string GetName() const { return m_name; };
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update() = 0;

	void UpdateLives(int lives) { m_lives -= lives; };
	int GetLives() const { return m_lives;};

private:
	std::string m_name;
	int m_lives;
	std::vector<std::unique_ptr<Heroes>> m_heroes;
};