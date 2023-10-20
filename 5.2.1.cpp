//laba 5.2.1
//varian 24
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void calculateS(const double x, const double eps, int& n, double& s) {
    n = 0;
    double a = 1;
    s = a;

    do {
        n++;
        double R = -x / n;
        a *= R;
        s += a;
    } while (abs(a) >= eps);
}

int main() {
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "Enter xp: "; cin >> xp;
    cout << "Enter xk: "; cin >> xk;
    cout << "Enter dx: "; cin >> dx;
    cout << "Enter eps: "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(10) << "ln(x+1)" << " |"
        << setw(10) << "S" << " |"
        << setw(5) << "n" << " |"
        << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk) {
        calculateS(x, eps, n, s);
        double lnValue = log(x + 1);

        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(6) << lnValue << " |"
            << setw(10) << setprecision(6) << s << " |"
            << setw(5) << n << " |"
            << endl;

        x += dx;
    }

    cout << "-------------------------------------------------" << endl;

    return 0;
}
