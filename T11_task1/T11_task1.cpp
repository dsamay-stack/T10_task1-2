#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// =========================
// 1) Perevantazhennia za TYPOm
// =========================
int square(int x) {
    return x * x;
}

double square(double x) {
    return x * x;
}

string square(const string& s) {
    return s + s;
}

// =========================
// 2) Perevantazhennia za KILKISTIU
// =========================
double avg(double a, double b) {
    return (a + b) / 2.0;
}

double avg(double a, double b, double c) {
    return (a + b + c) / 3.0;
}

double avg(double a, double b, double c, double d) {
    return (a + b + c + d) / 4.0;
}

int main() {
    cout << fixed << setprecision(6);

    cout << "PRYKLAD 1: perevantazhennia funktsii za typom argumentiv\n";

    int xi;
    double xd;
    string xs;

    cout << "Vvedit tsile chyslo (int): ";
    cin >> xi;
    cout << "Vvedit diisne chyslo (double): ";
    cin >> xd;
    cout << "Vvedit riadok (string): ";
    cin >> xs;

    cout << "square(int) = " << square(xi) << "\n";
    cout << "square(double) = " << square(xd) << "\n";
    cout << "square(string) = " << square(xs) << "\n";

    cout << "\nPRYKLAD 2: perevantazhennia funktsii za kilkistiu argumentiv\n";

    double a, b, c, d;
    cout << "Vvedit 4 diisni chysla a b c d: ";
    cin >> a >> b >> c >> d;

    cout << "avg(a,b) = " << avg(a, b) << "\n";
    cout << "avg(a,b,c) = " << avg(a, b, c) << "\n";
    cout << "avg(a,b,c,d) = " << avg(a, b, c, d) << "\n";

    return 0;
}
