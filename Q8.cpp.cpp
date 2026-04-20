#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Q8 - Student Score Writer & Reader
void line() {
    cout << "+----------------------+----------------------+\n";
}

void title(string text) {
    cout << "| " << setw(44) << left << text << "|\n";
}

int main() {
    string name[100];
    int score[100];
    int count = 0;

    ifstream inFile("scores.txt");

    while (inFile >> name[count] >> score[count]) {
        count++;
    }
    inFile.close();

    line();
    title("EXISTING SCORES");
    line();

    cout << "| " << setw(20) << left << "Player"
         << "| " << setw(20) << left << "Score" << "|\n";
    line();

    for (int i = 0; i < count; i++) {
        cout << "| " << setw(20) << left << name[i]
             << "| " << setw(20) << left << score[i] << "|\n";
    }

    line();

    string newName;
    int newScore;

    cout << "| Enter new player: ";
    cin >> newName;
    cout << "| Enter score: ";
    cin >> newScore;

    name[count] = newName;
    score[count] = newScore;
    count++;

    ofstream outFile("scores.txt");

    for (int i = 0; i < count; i++) {
        outFile << name[i] << " " << score[i] << endl;
    }
    outFile.close();

    int highest = score[0];
    string topPlayer = name[0];

    for (int i = 1; i < count; i++) {
        if (score[i] > highest) {
            highest = score[i];
            topPlayer = name[i];
        }
    }

    line();
    title("HIGHEST SCORE");
    line();

    cout << "| Player : " << setw(35) << left << topPlayer << "|\n";
    cout << "| Score  : " << setw(35) << left << highest << "|\n";

    line();

    return 0;
}
