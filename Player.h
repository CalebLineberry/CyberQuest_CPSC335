#include <string>
#include <vector>
#include <iostream>
# include "Mission.h"

using namespace std;

class Player {
    public:

        Player(string name);
        int getSkillLevel() const { return skillLevel; }
        int getToolsCount() const { return tools.size(); }
        int getDaysUsed() const { return daysUsed; }
        int getFinalScore() const;

        void train();
        void rest();

        void showStatistics();
        
        void addTool(std::string tool) { tools.push_back(tool); }
        void addCompletedMission(Mission& mission) { completedMissions.push_back(mission); }
        void updateReputation(int amount) { reputation += amount; }
        void updateCredits(int amount) { credits += amount; }


    
    private:
        std::string name;
        int energy;
        int skillLevel;
        int reputation;
        int credits;    
        int daysUsed;
        std::vector<std::string> tools;
        std::vector<Mission> completedMissions;

};

Player::Player(string name){
    this->name = name;
    energy = 100;
    skillLevel = 2;
    reputation = 0;
    credits = 50;
    daysUsed = 0;
}



void Player::train() {
    skillLevel += 8;
    energy -= 12;
    daysUsed += 1;
    cout << "==============================" << endl;
    cout << name << " is Training..." << endl;
    cout << "New Skill Level: " << skillLevel << " (+8)\n New Energy Level: " << energy << " (-12)\n Days used: " << daysUsed << " (+1)" << endl;
    cout << "==============================" << endl;
}

void Player::rest() {
    energy += 15;
    daysUsed += 1;
    cout << "==============================" << endl;
    cout << name << " is Resting..." << endl;
    cout << "New Energy Level: " << energy << " (+15)\n Days used: " << daysUsed << " (+1)" << endl;
    
    cout << "==============================" << endl;
}

void Player::showStatistics() {
    cout << "==============================" << endl;
    cout << name << "'s Statistics:" << endl;
    cout << "Energy: " << energy << endl;
    cout << "Skill Level: " << skillLevel << endl;
    cout << "Reputation: " << reputation << endl;
    cout << "Credits: " << credits << endl;
    cout << "Days Used: " << daysUsed << endl;
    cout << "Tools: ";
    for (const auto& tool : tools) {
        cout << tool << " ";
    }
    cout << endl;
    cout << "==============================" << endl;
}

int Player::getFinalScore() const {
    return skillLevel + credits + reputation*2 + completedMissions.size()*20 + energy;
}