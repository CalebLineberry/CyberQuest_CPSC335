#pragma once

#include <vector>
#include "Mission.h"
#include "Player.h"

int missionChoice(std::vector<Mission>& missions, Player& player);
int shopSelect(Player& player, std::vector<Tool> tools);
