#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "AnimationData.h"

class Resources {
public:
	using AnimationMap = std::map<std::string, AnimationData>;
	static Resources& Instance() {
		static Resources instance;
		return instance;
	}

	sf::Font& getFont() { return m_font; }
	sf::Texture& getTexture(const std::string& type);
	static bool registerAnimation(const std::string& name, const AnimationData& animationData);
	static const AnimationData& getAnimation(const std::string& name);
private:
	Resources();

	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;

	sf::Font m_font;
	std::unordered_map<std::string, std::unique_ptr<sf::Texture>> m_texture;
	static AnimationMap& getAnimationMap()
	{
		static AnimationMap m_animationMap;
		return m_animationMap;
	}
};