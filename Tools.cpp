#include "Tools.h"
#include <string>

Tool::Tool(std::string name, int bonus, int cost) {
    this->name = name;
    this->bonus = bonus;
    this->cost = cost;
};

std::string Tool::getName() const {
    return name;
}

int Tool::getBonus() const {
    return bonus;
}

int Tool::getCost() const {
    return cost;
}
