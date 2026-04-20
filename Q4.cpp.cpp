#include <iostream>
#include <iomanip>
using namespace std;

// Q4 - Shape Calculator
void line() {
    cout << "+------------------------------------------------------------+\n";
}

void title(string text) {
    cout << "| " << setw(58) << left << text << "|\n";
}

class Rectangle {
private:
    double width, height;

public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    double getArea() { return width * height; }
    double getPerimeter() { return 2 * (width + height); }
    bool isSquare() { return width == height; }
};

int main() {
    line(); title("RECTANGLE CALCULATOR"); line();

    for (int i = 0; i < 3; i++) {
        double w, h;

        cout << "| Rectangle " << i + 1 << "\n";
        cout << "| Width  : "; cin >> w;
        cout << "| Height : "; cin >> h;

        Rectangle r(w, h);

        line();
        cout << "| Area       : " << setw(40) << left << r.getArea() << "|\n";
        cout << "| Perimeter  : " << setw(40) << r.getPerimeter() << "|\n";
        cout << "| Type       : " << setw(40)
             << (r.isSquare() ? "Square" : "Not Square") << "|\n";
        line();
    }

    return 0;
}
