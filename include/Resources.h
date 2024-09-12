#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

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
	sf::Texture& getTexture(TextureID num) { return m_texture[size_t(num)];}

private:
	Resources() {
		//m_texture.reserve(size_t(TextureID::END));
		m_texture.resize(size_t(TextureID::END));
		m_texture[size_t(TextureID::T_TILE_BROWN)].loadFromFile("Tile1.png");
		m_texture[size_t(TextureID::T_TILE_LIGHT)].loadFromFile("Tile2.png");
	}

	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;

	sf::Font m_font;
	std::vector<sf::Texture> m_texture;
};