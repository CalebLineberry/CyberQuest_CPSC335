#include <string>
#include <vector>
#include "Player.h"

using namespace std;

class Mission{
    public:
        Mission(string name, int difficulty, int rewardReputation, int rewardCredits, int energyCost);
        bool attemptMission(const Player& player);

    private:
        string name;
        int difficulty;
        int rewardReputation;
        int rewardCredits;
        int energyCost;
};

Mission::Mission(string name, int difficulty, int rewardReputation, int rewardCredits, int energyCost) {
    this->name = name;
    this->difficulty = difficulty;
    this->rewardReputation = rewardReputation;
    this->rewardCredits = rewardCredits;
    this->energyCost = energyCost;
}

bool Mission::attemptMission(const Player& player) {
    int power = (rand() % 10) + player.getSkillLevel() + player.getToolsCount() * 4;
    return power >= difficulty;    
}