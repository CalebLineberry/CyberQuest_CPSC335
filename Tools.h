#pragma once

#include <string>

class Tool {
    public:
        Tool(std::string name, int bonus, int cost);
        std::string getName() const;
        int getBonus() const;
        int getCost() const;
    private:
        std::string name;
        int bonus;
        int cost;
};


    