#include <iostream>
#include <iomanip>
using namespace std;

// Q6 - Dynamic Student List
void line() {
    cout << "+------------------------------------------------------------+\n";
}

void title(string text) {
    cout << "| " << setw(58) << left << text << "|\n";
}

int main() {
    int n;

    line(); title("DYNAMIC STUDENT LIST"); line();

    cout << "| Enter number of students: ";
    cin >> n;
    cin.ignore();

    string* students = new string[n];

    for (int i = 0; i < n; i++) {
        cout << "| Name " << i + 1 << ": ";
        getline(cin, students[i]);
    }

    line();
    title("STUDENT LIST");
    line();

    for (int i = 0; i < n; i++) {
        cout << "| " << setw(58) << left << students[i] << "|\n";
    }

    line();

    delete[] students;
    return 0;
}
