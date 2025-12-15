#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(int choice, double x, bool& ok) {
    ok = true;
    switch (choice) {
    case 1: return sin(x);
    case 2: return cos(x);
    case 3: return exp(x);
    case 4:
        if (x <= 0) { ok = false; return 0; }
        return log(x); // ln(x)
    case 5: return x * x;
    case 6:
        if (x == 0) { ok = false; return 0; }
        return 1.0 / x;
    default:
        ok = false;
        return 0;
    }
}

int main() {
    cout << "MENU funktsii:\n";
    cout << "1) sin(x)\n";
    cout << "2) cos(x)\n";
    cout << "3) exp(x)\n";
    cout << "4) ln(x)  (x > 0)\n";
    cout << "5) x^2\n";
    cout << "6) 1/x   (x != 0)\n";
    cout << "Obyrai nomer (1-6): ";

    int choice;
    cin >> choice;

    double a, b, h;
    cout << "Vvedit pochatok vidrizka a: ";
    cin >> a;
    cout << "Vvedit kinets vidrizka b: ";
    cin >> b;
    cout << "Vvedit krok h (>0): ";
    cin >> h;

    if (h <= 0) {
        cout << "Pomylka: krok h maie buty dodatnii.\n";
        return 0;
    }
    if (a > b) {
        cout << "Pomylka: a ne mozhe buty bilshym za b.\n";
        return 0;
    }

    cout << fixed << setprecision(6);
    cout << "\n    x\t\tf(x)\n";
    cout << "----------------------------\n";

    // Tabuliuvannia do b vkluchno
    for (double x = a; x <= b + 1e-12; x += h) {
        bool ok;
        double y = f(choice, x, ok);

        cout << x << "\t";
        if (ok) cout << y << "\n";
        else   cout << "nevyznacheno\n";
    }

    return 0;
}
