#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Q7 - Student Record File Writer & Reader
void line() {
    cout << "+----------------------+----------------------+\n";
}

void title(string text) {
    cout << "| " << setw(44) << left << text << "|\n";
}

int main() {
    ofstream outFile("students.txt");

    string name;
    float grade;

    line(); title("STUDENT FILE WRITER"); line();

    for (int i = 0; i < 3; i++) {
        cout << "| Name  : ";
        cin >> name;
        cout << "| Grade : ";
        cin >> grade;

        outFile << name << " " << grade << endl;
    }

    outFile.close();

    cout << "| Records saved successfully.          |\n";

    ifstream inFile("students.txt");

    cout << "\n";
    line();
    title("STORED RECORDS");
    line();

    cout << "| " << setw(20) << left << "Name"
         << "| " << setw(20) << left << "Grade" << "|\n";
    line();

    while (inFile >> name >> grade) {
        cout << "| " << setw(20) << left << name
             << "| " << setw(20) << left << fixed << setprecision(1) << grade
             << "|\n";
    }

    line();

    inFile.close();
    return 0;
}
