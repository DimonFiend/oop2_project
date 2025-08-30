#pragma once
#include <utility>
#include <array>
#include "macros.h"

class ComputerPlayer;
class BuyingStateUnit;
class ObjectContainers;

using SelectedItem = std::pair<std::array<std::unique_ptr<BuyingStateUnit>, Macros::MAX_BOARD_SLOTS>*, BuyingStateUnit*>;
typedef std::array<std::unique_ptr<BuyingStateUnit>, Macros::MAX_BOARD_SLOTS> Units;
using ComputerVector = std::vector<std::unique_ptr<ComputerPlayer>>;