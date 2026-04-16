#include <string>
#include <vector>
#include <iostream>
#include "Mission.h"
#include "Player.h"
using namespace std;

int missionChoice(vector<Mission>& missions, Player& player) {
    while (true) {
        cout << "-----------------------------" << endl;
        cout << "Missions:" << endl;
            for (int i = 0; i < missions.size(); ++i) {
                cout << i + 1 << ". " << missions[i].getName() << " (Difficulty: " << missions[i].getDifficulty() << ", Reputation: " << missions[i].getRewardReputation() << ", Credits: " << missions[i].getRewardCredits() << ", Energy Cost: " << missions[i].getEnergyCost() << ")" << endl;
            }
            cout << ">> Choose a mission to attempt (or 0 to go back): ";
            int missionChoice;
            cin >> missionChoice;
            if (missionChoice == 0) {
                return missionChoice;
            }else if(missionChoice > 0 && missionChoice <= missions.size()) {
                Mission& selectedMission = const_cast<Mission&>(missions[missionChoice - 1]);
                selectedMission.attemptMission(player);
                return missionChoice;
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
    }
}

    int shopSelect(Player& player, vector<Tool> tools) {
    while (true){
            cout << "-----------------------------" << endl;
            cout << "Shop:" << endl;
            for (int i = 0; i < tools.size(); ++i) {
                cout << i + 1 << ". " << tools[i].getName() << " (Bonus: " << tools[i].getBonus() << ", Cost: " << tools[i].getCost() << " credits)" << endl;
            }
            cout << "Your Credits: " << player.getCredits() << endl;
            cout << ">> Choose a tool to purchase (or 0 to go back): ";
            int shopChoice;
            cin >> shopChoice;
            if (shopChoice == 0) {
                return shopChoice;
            } else if (shopChoice > 0 && shopChoice <= tools.size()) {
                Tool selectedTool = tools[shopChoice - 1];
                if (player.getCredits() >= selectedTool.getCost()) {
                    player.addTool(selectedTool);
                    player.updateCredits(-selectedTool.getCost());
                    cout << "You purchased: " << selectedTool.getName() << endl;
                    return shopChoice;
                } else {
                    cout << "You don't have enough credits to purchase this tool." << endl;
                }
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
    }
    return 0;
    }