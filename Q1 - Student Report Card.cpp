#include <iostream>
#include <iomanip>
using namespace std;

// Q1 - Student Report Card
struct Student {
    string name;
    float midterm, final_exam, average;
};

void line() {
    cout << "+----------------------+----------+----------+----------+----------+\n";
}

void title() {
    cout << "+---------------------------------------------------------------+\n";
    cout << "|                  STUDENT GRADE REPORT                         |\n";
    cout << "+---------------------------------------------------------------+\n";
}

int main() {
    Student s[5];

    title();

    for (int i = 0; i < 5; i++) {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Name        : ";
        getline(cin, s[i].name);

        cout << "Midterm     : ";
        cin >> s[i].midterm;

        cout << "Final Exam  : ";
        cin >> s[i].final_exam;
        cin.ignore();

        s[i].average = (s[i].midterm + s[i].final_exam) / 2;
    }

    cout << "\n";

    line();
    cout << "| " << left << setw(20) << "Name"
         << "| " << setw(8) << "Midterm"
         << "| " << setw(8) << "Final"
         << "| " << setw(8) << "Average"
         << "| " << setw(8) << "Remark" << "|\n";
    line();

    for (int i = 0; i < 5; i++) {
        cout << "| " << setw(20) << s[i].name
             << "| " << setw(8) << fixed << setprecision(1) << s[i].midterm
             << "| " << setw(8) << s[i].final_exam
             << "| " << setw(8) << s[i].average
             << "| " << setw(8) << (s[i].average >= 75 ? "Passed" : "Failed")
             << "|\n";
    }

    line();

    return 0;
}
