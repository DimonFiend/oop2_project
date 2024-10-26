#include "Resources.h"
#include <fstream>
#include <sstream>
#include <iostream>

Resources::Resources() {
    std::ifstream file("Textures.txt");
    try {
        if (!file.is_open()) {
            throw std::runtime_error("File 'Textures.txt' not found");
        }

        std::string line;
        while (std::getline(file, line)) {
            std::string name;
            std::string path;

            std::istringstream iss(line);
            iss >> name >> path;

            m_texture[name] = std::make_unique<sf::Texture>();
            if (!m_texture[name]->loadFromFile(path)) {
                throw std::runtime_error("Failed to load texture from file: " + path);
            }
        }
        file.close();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    m_font.loadFromFile("ComicFont.ttf");
}

sf::Texture& Resources::getTexture(const std::string& type)
{
    auto it = m_texture.find(type);
    if (it != m_texture.end()) {
        return *it->second;
    }
    // Handle the case when the texture is not found
    throw std::runtime_error("Texture not found for type: " + type);
}