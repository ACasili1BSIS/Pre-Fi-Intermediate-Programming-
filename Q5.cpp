#include <iostream>
#include <iomanip>
using namespace std;

// Q5 - Pointer-Based String
void line() {
    cout << "+------------+------+------+------+------+------+\n";
}

void title(string text) {
    cout << "+------------------------------------------------+\n";
    cout << "| " << setw(46) << left << text << "|\n";
    cout << "+------------------------------------------------+\n";
}

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main() {
    int arr[5], original[5];

    title("POINTER-BASED SORTING");

    cout << "| Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        original[i] = arr[i];
    }

    bubbleSort(arr, 5);

    cout << "\n";

    line();
    cout << "| " << setw(10) << "State"
         << "| " << setw(4) << "1"
         << "| " << setw(4) << "2"
         << "| " << setw(4) << "3"
         << "| " << setw(4) << "4"
         << "| " << setw(4) << "5"
         << "|\n";
    line();

    cout << "| " << setw(10) << "Before";
    for (int i = 0; i < 5; i++) {
        cout << "| " << setw(4) << original[i];
    }
    cout << "|\n";

    cout << "| " << setw(10) << "After";
    for (int i = 0; i < 5; i++) {
        cout << "| " << setw(4) << arr[i];
    }
    cout << "|\n";

    line();

    return 0;
}
