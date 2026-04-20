#include <iostream>
#include <iomanip>
using namespace std;

// Q3 - Bank Account System
void line() {
    cout << "+------------------------------------------------------------+\n";
}

void title(string text) {
    cout << "| " << setw(58) << left << text << "|\n";
}

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string name, double initial) {
        accountHolder = name;
        balance = initial;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "| ✔ Deposit successful                                      |\n";
    }

    void withdraw(double amount) {
        if (amount > balance)
            cout << "| ✖ Insufficient funds                                      |\n";
        else {
            balance -= amount;
            cout << "| ✔ Withdrawal successful                                   |\n";
        }
    }

    void displayBalance() {
        line();
        title("ACCOUNT DETAILS");
        line();
        cout << "| Account Holder : " << setw(36) << left << accountHolder << "|\n";
        cout << "| Balance        : PHP " << setw(30) << fixed << setprecision(2) << balance << "|\n";
        line();
    }
};

int main() {
    string name;
    double initial;

    line();
    title("BANK ACCOUNT SYSTEM");
    line();

    cout << "| Enter account holder: ";
    getline(cin, name);

    while (true) {
        cout << "| Initial deposit: ";
        cin >> initial;

        if (cin.fail() || initial < 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "| Invalid amount. Enter a non-negative value.               |\n";
        } else {
            break;
        }
    }

    BankAccount acc(name, initial);

    int choice;
    do {
        line();
        title("MAIN MENU");
        line();

        cout << "| [1] Deposit                                               |\n";
        cout << "| [2] Withdraw                                              |\n";
        cout << "| [3] Check Balance                                         |\n";
        cout << "| [4] Exit                                                  |\n";
        line();

        cout << "| Enter choice: ";
        cin >> choice;

        double atm;

        switch (choice) {
            case 1:
                cout << "| Enter amount: ";
                cin >> atm;
                acc.deposit(atm);
                break;

            case 2:
                cout << "| Enter amount: ";
                cin >> atm;
                acc.withdraw(atm);
                break;

            case 3:
                acc.displayBalance();
                break;

            case 4:
                cout << "| Exiting system...                                         |\n";
                break;

            default:
                cout << "| Invalid choice!                                           |\n";
        }

    } while (choice != 4);

    line();
    title("THANK YOU FOR USING THE SYSTEM!");
    line();

    return 0;
}
