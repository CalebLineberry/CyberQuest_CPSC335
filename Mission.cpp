#include "Mission.h"
#include "Player.h"
#include <cstdlib>

Mission::Mission(const std::string& name, int difficulty, int rewardReputation, int rewardCredits, int energyCost){
    this->name = name;
    this->difficulty = difficulty;
    this->rewardReputation = rewardReputation;
    this->rewardCredits = rewardCredits;
    this->energyCost = energyCost;
}

std::string Mission::getName() const {
    return name;
}

int Mission::getDifficulty() const {
    return difficulty;
}

int Mission::getRewardReputation() const {
    return rewardReputation;
}

int Mission::getRewardCredits() const {
    return rewardCredits;
}

int Mission::getEnergyCost() const {
    return energyCost;
}

bool Mission::attemptMission(Player& player) {
    std::cout << "==============================" << std::endl;
    std::cout << "Attempting mission: " << name << std::endl;
    std::cout << "Mission Difficulty: " << difficulty << std::endl;
    std::cout << "Energy Cost: " << energyCost << std::endl;
    std::cout << std::endl;
    std::cout << "------Calculating Power-------" << std::endl;

    std::cout << "Player Skill Level: " << player.getSkillLevel() << std::endl;
    
    std::vector<Tool> playerTools = player.getTools();
    
    int totalToolBonus = 0;
    for (const auto& tool : playerTools) {
        totalToolBonus += tool.getBonus();
    }
    std::cout << "Power from Tools: " << totalToolBonus << std::endl;
    int luck = std::rand() % 10;
    std::cout << "Power from Luck: " << luck << std::endl;
    int power = luck + player.getSkillLevel() + totalToolBonus;
    std::cout << "Total Power: " << power << std::endl;
    
    player.addDay();

    if(power >= difficulty){
        std::cout << std::endl;
        std::cout << "Mission Success!" << std::endl;
        std::cout << "Gained " << rewardReputation << " Reputation and " << rewardCredits << " Credits." << std::endl;
        std::cout << "Lost " << energyCost << " Energy." << std::endl;
        player.updateReputation(rewardReputation);
        player.updateCredits(rewardCredits);
        player.updateEnergy(-energyCost);
        player.addCompletedMission(name);

        return true;
    } else {
        std::cout << std::endl;
        std::cout << "Mission Failed!" << std::endl;
        std::cout << "Lost " << energyCost << " Energy." << std::endl;
        player.updateEnergy(-energyCost);

        return false;
    }    
}
