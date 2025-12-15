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
    cout << "MENU funktsii dlia intehruvannia:\n";
    cout << "1) sin(x)\n";
    cout << "2) cos(x)\n";
    cout << "3) exp(x)\n";
    cout << "4) ln(x)  (x > 0)\n";
    cout << "5) x^2\n";
    cout << "6) 1/x   (x != 0)\n";
    cout << "Obyrai nomer (1-6): ";

    int choice;
    cin >> choice;

    double a, b;
    cout << "Vvedit pochatok vidrizka a: ";
    cin >> a;
    cout << "Vvedit kinets vidrizka b: ";
    cin >> b;

    int n;
    cout << "Vvedit kilkist podiliv n (parne, n>=2): ";
    cin >> n;

    if (n < 2 || n % 2 != 0) {
        cout << "Pomylka: n maie buty parnym ta n >= 2.\n";
        return 0;
    }

    double h = (b - a) / n;

    bool ok0, okn;
    double fx0 = f(choice, a, ok0);
    double fxn = f(choice, b, okn);

    if (!ok0 || !okn) {
        cout << "Pomylka: funktsiia ne vyznachena na mezhiakh vidrizka.\n";
        return 0;
    }

    double sum_odd = 0.0;
    double sum_even = 0.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        bool ok;
        double fx = f(choice, x, ok);

        if (!ok) {
            cout << "Pomylka: funktsiia ne vyznachena v tochtsi x = "
                << fixed << setprecision(6) << x << "\n";
            return 0;
        }

        if (i % 2 == 1) sum_odd += fx;
        else            sum_even += fx;
    }

    double I = (h / 3.0) * (fx0 + fxn + 4.0 * sum_odd + 2.0 * sum_even);

    cout << fixed << setprecision(10);
    cout << "Krok h = " << h << "\n";
    cout << "Intehral za metodom Simpsona = " << I << "\n";
    return 0;
}
