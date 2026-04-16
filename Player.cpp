#include <string>
#include <vector>
#include <iostream>
#include "Mission.h"
#include "Tools.h"
#include "Player.h"
using namespace std;

Player::Player(const std::string& name){
    this->name = name;
    energy = 100;
    skillLevel = 2;
    reputation = 0;
    credits = 50;
    daysUsed = 1;
}

int Player::getSkillLevel() const {
    return skillLevel;
}
vector<Tool> Player::getTools() const {
    return tools;
}
int Player::getDaysUsed() const {
    return daysUsed;
}
int Player::getCredits() const {
    return credits;
}


void Player::addTool(const Tool& tool) {
    tools.push_back(tool);
}

void Player::addCompletedMission(const std::string& missionName) {
    completedMissions.push_back(missionName);
}

void Player::updateReputation(int amount) {
    reputation += amount;
}

void Player::updateCredits(int amount) {
    credits += amount;
}

void Player::updateEnergy(int amount) {
    energy += amount;
}

void Player::addDay() {
    daysUsed += 1;
}

void Player::train() {
    skillLevel += 8;
    energy -= 12;
    daysUsed += 1;
    cout << "==============================" << endl;
    cout << "Training..." << endl;
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
        cout << tool.getName() << " ";
    }
    cout << endl;
    cout << "Completed Missions: ";
    for (const auto& missionName : completedMissions) {
        cout << missionName << " ";
    }
    cout << endl;

}

int Player::getFinalScore() const {
    return skillLevel + credits + reputation*2 + completedMissions.size()*20 + energy;
}