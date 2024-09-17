#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

enum class TextureID {
	T_TILE_BROWN,
	T_TILE_LIGHT,
	END
};

class Resources {
public:
	static Resources& Instance() {
		static Resources instance;
		return instance;
	}

	sf::Font& getFont() { return m_font; }
	sf::Texture& getTexture(const std::string& type);

private:
	Resources();

	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;

	sf::Font m_font;
	std::unordered_map<std::string, std::unique_ptr<sf::Texture>> m_texture;
};