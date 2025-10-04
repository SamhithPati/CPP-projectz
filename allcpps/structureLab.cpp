// Samhith Patibandla
// 11/18/2023
// Soccer Statistics Calculator Program

#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>

using namespace std;

const int NAME_LENGTH = 50;
const int NUM_PLAYERS = 4;
const int NUM_TEAMS = 3;

// Struct to represent a soccer player
struct SoccerPlayer {
    char playerName[NAME_LENGTH] = "None";
    int goalsScored = 0;
};

// Struct to represent a soccer team
struct SoccerTeam {
    char teamName[NAME_LENGTH] = "None";
    int gamesPlayed = 0, totalWins = 0;
    SoccerPlayer socPlayer[NUM_PLAYERS];
};

// Function Prototypes
void showCopyright();
void showStats(SoccerTeam team[], bool);
void getTeamInfo(SoccerTeam team[]);
bool validate(int inputNum, string fldName);

int main()
{
    showCopyright();

    SoccerTeam socTeams[NUM_TEAMS];

    cout << "Data after Initialization: \n";
    showStats(socTeams, false);

    getTeamInfo(socTeams);

    cout << "\n\nData After User Input:";
    showStats(socTeams, true);

    cout << endl << endl;

    system("pause");
    return 0;
}

// Display copyright information
void showCopyright() {
    cout << "Lab 9 - Structures\n";
    cout << "Copyright ©2022 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n";
    cout << "\n\tWelcome to the CMSY-141 Soccer Statistics Calculator\n";
}

// Display soccer team statistics
void showStats(SoccerTeam team[], bool checkPlayer) {
    double averageGoals;
    for (int i = 0; i < NUM_TEAMS; i++) {
        cout << "\n\nThe team: " << team[i].teamName << " has played " << team[i].gamesPlayed << " games\n";
        cout << "\tTheir record is " << team[i].totalWins << " wins and " << (team[i].gamesPlayed - team[i].totalWins) << " losses.\n";
        for (int j = 0; j < NUM_PLAYERS; j++) {
            if (checkPlayer && team[i].socPlayer[j].goalsScored == 0) {
                continue;
            }
            cout << "\nPlayer: " << team[i].socPlayer[j].playerName << ", has " << team[i].socPlayer[j].goalsScored << " goals.";
            averageGoals = team[i].socPlayer[j].goalsScored / double(team[i].gamesPlayed);
            if (averageGoals == 0 || isnan(averageGoals)) {
                cout << "\n\tThe average goals are:  No games Played.";
            }
            else {
                cout << "\n\tThey average " << fixed << setprecision(2) << averageGoals << " goals per game.";
            }
        }
    }
}

// Gather user input for soccer teams
void getTeamInfo(SoccerTeam team[]) {
    bool valGoals;
    cout << "\n\nUser Input: \n";

    for (int i = 0; i < NUM_TEAMS; i++) {
        cout << "\nEnter the teams name: ";
        cin >> ws; // Work around for cin.ignore()
        // cin.ignore(); - not working
        cin.getline(team[i].teamName, NAME_LENGTH);
        do {
            cout << "Enter the number of games played: ";
            cin >> team[i].gamesPlayed;
        } while (!validate(team[i].gamesPlayed, "games"));

        do {
            cout << "Enter the number of games won: ";
            cin >> team[i].totalWins;
            if (team[i].totalWins > team[i].gamesPlayed) {
                cout << "Error - the number of games won cannot be greater than the number of games played. Please reenter\n\n";
            }
        } while (!validate(team[i].totalWins, "games won") || (team[i].totalWins > team[i].gamesPlayed));

        char tempString[NAME_LENGTH];

        for (int j = 0; j < NUM_PLAYERS; j++) {
            cout << "\tEnter the name of player " << j + 1 << ": ";
            cin.ignore();
            cin.getline(team[i].socPlayer[j].playerName, NAME_LENGTH);
            strcpy_s(tempString, team[i].socPlayer[j].playerName);

            // Convert both the input and comparison strings to lowercase for case-insensitive check
            for (char& c : tempString) {
                c = tolower(c);
            }

            if (_stricmp(tempString, "none") == 0) {
                break;
            }

            do {
                valGoals = true;
                cout << "\tEnter the goals scored " << j + 1 << ": ";
                cin >> team[i].socPlayer[j].goalsScored;
                if (team[i].socPlayer[j].goalsScored < 0) {
                    cout << "\tError - the number of goals must be greater than zero. Please reenter.\n\n";
                    valGoals = false;
                }
            } while (!valGoals);
            //cin.ignore();
        }
    }
}

// Function to validate input number (must be non-negative)
bool validate(int inputNum, string fldName)
{
    bool valInput = true;
    if (inputNum < 0)
    {
        cout << "Error - number of " << fldName << " must be greater than or equal to zero. Please reenter.\n\n";
        valInput = false;
    }
    return valInput;
}