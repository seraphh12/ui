#include <iostream>
#include <fstream>
#include <vector>
#include "leaderboard.h"

using namespace std;

void savePlayer(string name) {
    ofstream file("player.txt", ios::app);
    file << name << endl;
    file.close();
}

vector<string> loadPlayers() {
    ifstream file("player.txt");

    vector<string> players;
    string name;

    while (getline(file, name)) {
        if (!name.empty()) {
            players.push_back(name);
        }
    }

    file.close();
    return players;
}
