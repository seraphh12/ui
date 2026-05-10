#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "leaderboard.h"
using namespace std;

const int WIDTH = 86;

//for entering name inside the design
void gotoxy(int x, int y) {
    COORD coord;

    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void line() {
    color(13);
    cout << string(WIDTH, '-') << endl;
}

void printBorder(const string& content, int textColor = 15) {

    color(13); 
    cout << "|";

    color(textColor);

    cout << content;

    color(13); 
    cout << "|" << endl;

    color(7); 
}


void printCentered(const string& text, int textColor = 15) {

    int padding = (WIDTH - 2 - text.length()) / 2;

    string content =
        string(padding, ' ') +
        text +
        string(WIDTH - 2 - padding - text.length(), ' ');

    printBorder(content, textColor);
}

void emptyLine() {
    printBorder(string(WIDTH - 2, ' '));
    printBorder(string(WIDTH - 2, ' '));
}

void menuTitle(int select) {

    string choice[4] = {
        "S T A R T",
        "T U T O R I A L",
        "L E A D E R B O A R D",
        "E X I T"
    };

    for (int i = 0; i < 4; i++) {

        string label = (i == select ? ">> " : "   ") + choice[i];

        int padding = WIDTH - 2 - label.length();

        string content =
            string(padding / 2, ' ') +
            label +
            string(padding - padding / 2, ' ');

        int textColor = (i == select) ? 15 : 8;

        printBorder(content, textColor);

        if (i != 3)
            printBorder(string(WIDTH - 2, ' '), 7);
    }

    emptyLine();
}


void title() {
    emptyLine();
    color(11);
    printCentered("____________________________________________________________________");
    printCentered("| |  _ | ___   __ _  __| |  / ___|_ __ ___  ___ ___(_)_ ___  __ _  |");
    printCentered("| | |_) / _ | / _` |/ _` | | |   | '__/ _ || __/ __| | '_  |/ _` | |");
    printCentered("| |  _ < (_) | (_| | (_| | | |___| | | (_) |__ |__ | | | | | (_| | |");
    printCentered("| |_| |_|___/|__,_||__,__| |_____|_| |___/|___/___/|_|_||_||__,  | |");
    printCentered("|    	            C h a l l e n g e                       |___/ |");
    printCentered("|___________________________________________________________________");
    color(11);
    emptyLine();
}


void console() {
    color(15);
    cout << "|                                                                                    |" << endl;
    cout << "|                                                                                    |" << endl;
    cout << "|           ____                  __        __                     ____              |" << endl;
    cout << "|          |    |                (__)      (__)                   (    )             |" << endl;
    cout << "|          |    |                START     MENU                   (____)             |" << endl;
    cout << "|    ______|    |______                                     ____          ____       |" << endl;
    cout << "|   |                  |                                   (    )        (    )      |" << endl;
    cout << "|   |______      ______|                                   (____)        (____)      |" << endl;
    cout << "|          |    |                                                  ____              |" << endl;
    cout << "|          |    |                                                 (    )             |" << endl;
    cout << "|          |____|                                                 (____)             |" << endl;
    cout << "|                               ______    ______                                     |" << endl;
    cout << "|                              (______)  (______)                                    |" << endl;
    cout << "|                                                                                    |" << endl;
    cout << "|                                                                                    |" << endl;
    color(7);
}

void draw(int select) {
    system("cls");
    line();
    title();
    menuTitle(select);
    emptyLine();
    line();
    console();
    line();
}

void startScreen(const string& name = "") {
    system("cls");

    line();
    title();

    if (name == "") {
        printCentered("E N T E R   N A M E : ");
        printCentered("                      ");
    }
    else {
        printCentered("P L A Y E R : " + name);
        emptyLine();
        printCentered("S E L E C T   D I F F I C U L T Y : ");
    }

    emptyLine();
    emptyLine();
    emptyLine();
    line();
    console();
    line();
}

void tutorialScreen() {
    system("cls");

    line();
    title();

    printCentered(" H O W  T O  P L A Y :");
    printCentered("                      ");

    emptyLine();
    printCentered(" __________________________________________");
    printCentered("| - Use UP and DOWN Arrow Keys to move     |");
    printCentered("| - Dodge trucks (#####) in the ROAD ZONE  | ");
    printCentered("| - Hop on logs (====) in the RIVER ZONE   | ");
    printCentered("| - Reach the finish line 5 times to win!  | ");
    printCentered(" __________________________________________");

    emptyLine();
    emptyLine();
    emptyLine();
    line();
    console();
    line();
}

void leaderScreen() {
    system("cls");

    line();
    title();

    printCentered(" L E A D E R B O A R D:");
    printCentered("                      ");

    vector<string> players = loadPlayers();

        for (int i = 0; i < players.size(); i++) {
            printCentered(players[i]);
        }

    emptyLine();
    emptyLine();
    emptyLine();
    line();
    console();
    line();
}

int chooseDifficulty(string name) {

    int selectDifficulty = 0;

    string diff[3] = {
        "E A S Y",
        "N O R M A L",
        "H A R D"
    };

    while (true) {

        startScreen(name);

        //to print difficulty choices inside
        for (int i = 0; i < 3; i++) {
            string label;

            if (i == selectDifficulty) {
                color(15);
                label = ">> " + diff[i];
            }
            else {
                color(8);
                label = "   " + diff[i];
            }
            
            // CENTER FORMULA
            int x = (WIDTH / 2) - (label.length() / 2);

            // SPACING BETWEEN OPTIONS
            int y = 16 + (i * 2);

            gotoxy(x, y);

            cout << label;
        }

        color(7);

        emptyLine();

        int key = _getch();

        if (key == 224) {

            key = _getch();

            if (key == 72) { // UP
                selectDifficulty = (selectDifficulty - 1 + 3) % 3;
            }

            else if (key == 80) { // DOWN
                selectDifficulty = (selectDifficulty + 1) % 3;
            }
        }

        else if (key == 13) { // ENTER
            return selectDifficulty;
        }
    }
}

void startChoice() {
    string name;

    startScreen(name);

    // move cursor INSIDE the box
    gotoxy(41, 12);
    getline(cin, name);

    savePlayer(name);
    int difficulty = chooseDifficulty(name);

    string diffText;

    if (difficulty == 0)
        diffText = "EASY";
    else if (difficulty == 1)
        diffText = "NORMAL";
    else if (difficulty == 2)
        diffText = "HARD";

    system("cls");

    line();
    title();
    emptyLine();
    printCentered("P L A Y E R : " + name);
    printCentered("D I F F I C U L T Y : " + diffText);
    line();

    system("pause");
}

void menuInput(int& select, bool& running) {
    int key = _getch();

        if (key == 224) {

            key = _getch();

            if (key == 72) { // UP
                select = (select - 1 + 4) % 4;
            }

            else if (key == 80) { // DOWN
                select = (select + 1) % 4;     // DOWN
            }
        }

        else if (key == 13) {

            system("cls");

            if (select == 0) {
                startChoice();
            }

            else if (select == 1) {
                tutorialScreen();
            }

            else if (select == 2) {
               leaderScreen();
            }

            else if (select == 3) {
                cout << "Exiting game...\n";
                running = false;
            }

            system("pause");
        }
}

int main() {
    int select = 0; //starts in start
    bool running = true;
    
    while (running) {
        draw(select);
        menuInput(select, running);
    }

    vector<string> player = loadPlayers();

    return 0;
}


