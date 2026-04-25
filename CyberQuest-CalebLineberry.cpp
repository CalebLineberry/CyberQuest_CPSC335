#include <string>
#include <vector>
#include <iostream>
#include "Mission.h"
#include "Player.h"
#include "Tools.h"
#include "Actions.h"
using namespace std;


int main() {
    cout << "===============================" << endl;
    cout << "           CyberQuest    " << endl;
    cout << "       By Caleb Lineberry   " << endl;
    cout << "===============================" << endl;
    cout << endl;

    vector<Mission> missions = {
        Mission("Virginia Cyber Range Labs", 10, 10, 20, 10),
        Mission("Security+ Exam", 20, 20, 40, 15),
        Mission("Vulnerable Network Analysis", 30, 30, 60, 20),
        Mission("Ransomware Response", 40, 40, 80, 25),
        Mission("Advanced Persistent Threat", 50, 50, 100, 30),
        Mission("Doomsday Zero-Day Scenario", 60, 60, 120, 35)
    };

    vector<Tool> tools = {
        Tool("Basic Firewall", 4, 30),
        Tool("Antivirus Software", 8, 60),
        Tool("Intrusion Detection System", 12, 90),
        Tool("Encryption Software", 16, 120),
        Tool("Penetration Testing Tools", 20, 150),
        Tool("AI Threat Intelligence", 25, 180)
        
    };

    vector<string> ranks = {
        "Cybersecurity Novice",
        "Cybersecurity Intern",
        "Junior Cybersecurity Specialist",
        "Senior Cybersecurity Specialist",
        "Cybersecurity Legend"
    };

    string name;
    cout << "Enter your name: ";
    cin >> name;
    Player player(name);

    while (player.getDaysUsed() <= 12) {
        cout << endl;
        cout << "=========Day " << player.getDaysUsed() << " of 12==========" << endl;
        cout << "1. View Stats\n2. Train\n3. Rest\n4. Visit Shop\n5. Attempt Mission\n6. Exit Game\nChoose an Action: ";
        int choice;
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a valid integer: ";
        }
        cout << endl;

        if (choice == 1) {
            player.showStatistics();
        } else if (choice == 2) {
            player.train();
        } else if (choice == 3) {
            player.rest();
        } else if (choice == 4) {
            shopSelect(player, tools);
        } else if (choice == 5) {
            missionChoice(missions, player);
        } else if (choice == 6) {
            cout << "Exiting game. Thanks for playing!" << endl;
            cout << "Final Score: " << player.getFinalScore() << endl;

            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    if (player.getDaysUsed() > 12) {
        cout << endl;
        cout << "Game Over!" << endl;
        cout << "Final Score: " << player.getFinalScore() << endl;

    }

    if (player.getFinalScore() <= 100) {
        cout << "Rank: " << ranks[0] << endl;
    } else if (player.getFinalScore() <= 160) {
        cout << "Rank: " << ranks[1] << endl;
    } else if (player.getFinalScore() <= 220) {
        cout << "Rank: " << ranks[2] << endl;
    } else if (player.getFinalScore() <= 280) {
        cout << "Rank: " << ranks[3] << endl;
    } else {
        cout << "Rank: " << ranks[4] << endl;
    }

    return 0;
}