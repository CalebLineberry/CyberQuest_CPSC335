#pragma once

#include <string>

class Player;

class Mission {
    public:
        Mission(const std::string& name, int difficulty, int rewardReputation, int rewardCredits, int energyCost);
        bool attemptMission(Player& player);

        std::string getName() const;
        int getDifficulty() const;
        int getRewardReputation() const;
        int getRewardCredits() const;
        int getEnergyCost() const;

    private:
        std::string name;
        int difficulty;
        int rewardReputation;
        int rewardCredits;
        int energyCost;
};

