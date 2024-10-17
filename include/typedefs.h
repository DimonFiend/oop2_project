#pragma once
#include <utility>
#include <array>
#include "macros.h"

class Unit;
class ObjectContainers;

using SelectedItem = std::pair<std::array<std::unique_ptr<Unit>, Macros::MAX_BOARD_SLOTS>*, Unit*>;
typedef std::array<std::unique_ptr<Unit>, Macros::MAX_BOARD_SLOTS> Units;