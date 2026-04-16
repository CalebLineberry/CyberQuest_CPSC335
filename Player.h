#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Tools.h"

class Player {
    public:

        Player(const std::string& name);
        int getSkillLevel() const;
        std::vector<Tool> getTools() const;
        int getDaysUsed() const;
        int getFinalScore() const;
        int getCredits() const;

        void train();
        void rest();

        void showStatistics();
        
        void addTool(const Tool& tool);
        void addCompletedMission(const std::string& missionName);
        void updateReputation(int amount);
        void updateCredits(int amount);
        void updateEnergy(int amount);
        void addDay();
    
    private:

        std::string name;
        int energy;
        int skillLevel;
        int reputation;
        int credits;
        int daysUsed;
        std::vector<Tool> tools;
        std::vector<std::string> completedMissions;

};

