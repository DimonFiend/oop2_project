#pragma once

#include "CharacterActions.h"

#include <SFML/Graphics.hpp>

#include <unordered_map>
#include <vector>

struct AnimationData
{
    using ListType = std::vector<sf::IntRect>;
    using DataType = std::unordered_map<CharacterActions, ListType>;
    DataType m_data;
};
