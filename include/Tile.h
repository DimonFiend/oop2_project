#pragma once

#include "GameObject.h"

class Tile : public GameObject {
public:
    Tile(const std::string& type, sf::Vector2f pos);
private:
   static bool m_bool_init;

};