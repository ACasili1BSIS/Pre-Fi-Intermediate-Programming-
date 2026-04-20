#include <iostream>
#include <iomanip>
using namespace std;

// Q2 - Product Inventory
struct Product {
    string name;
    int quantity;
    float price;
};

void line() {
    cout << "+----------------------+----------+----------+----------------+\n";
}

void title() {
    cout << "+------------------------------------------------------------+\n";
    cout << "|                 PRODUCT INVENTORY SYSTEM                   |\n";
    cout << "+------------------------------------------------------------+\n";
}

int main() {
    Product p[5];
    int n;

    
    title();

    while (true) {
        cout << "Enter number of products (1–5): ";
        cin >> n;

        if (cin.fail() || n < 1 || n > 5) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
        } else {
            cin.ignore();
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << endl;

        cout << "Name     : ";
        getline(cin, p[i].name);

        while (true) {
            cout << "Quantity : ";
            cin >> p[i].quantity;

            if (cin.fail() || p[i].quantity < 0) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid quantity. Enter a non-negative number.\n";
            } else break;
        }

        while (true) {
            cout << "Price    : ";
            cin >> p[i].price;

            if (cin.fail() || p[i].price < 0) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid price. Enter a non-negative value.\n";
            } else break;
        }

        cin.ignore();
    }

    float maxPrice = p[0].price;
    string maxProduct = p[0].name;

    cout << "\n";

    line();
    cout << "| " << left << setw(20) << "Product"
         << "| " << setw(8) << "Qty"
         << "| " << setw(8) << "Price"
         << "| " << setw(14) << "Total Value" << "|\n";
    line();

    for (int i = 0; i < n; i++) {
        float total = p[i].quantity * p[i].price;

        cout << "| " << setw(20) << p[i].name
             << "| " << setw(8) << p[i].quantity
             << "| " << setw(8) << fixed << setprecision(2) << p[i].price
             << "| " << setw(14) << total << "|\n";

        if (p[i].price > maxPrice) {
            maxPrice = p[i].price;
            maxProduct = p[i].name;
        }
    }

    line();

    cout << "| Most Expensive Product: "
         << setw(27) << left << maxProduct << "|\n";
    cout << "| Price: PHP "
         << setw(38) << left << fixed << setprecision(2) << maxPrice << "|\n";
    cout << "+------------------------------------------------------------+\n";

    return 0;
}
