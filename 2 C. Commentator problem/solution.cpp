#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x1, y1, r1;
    double x2, y2, r2;
    double x3, y3, r3;

    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    cin >> x3 >> y3 >> r3;

    // From:
    // r1^2 * ((x-x2)^2 + (y-y2)^2) = r2^2 * ((x-x1)^2 + (y-y1)^2)
    // r1^2 * ((x-x3)^2 + (y-y3)^2) = r3^2 * ((x-x1)^2 + (y-y1)^2)

    double A1 = 2*(r2*r2*x1 - r1*r1*x2);
    double B1 = 2*(r2*r2*y1 - r1*r1*y2);
    double C1 = r1*r1*(x2*x2 + y2*y2) - r2*r2*(x1*x1 + y1*y1);

    double A2 = 2*(r3*r3*x1 - r1*r1*x3);
    double B2 = 2*(r3*r3*y1 - r1*r1*y3);
    double C2 = r1*r1*(x3*x3 + y3*y3) - r3*r3*(x1*x1 + y1*y1);

    double det = A1*B2 - A2*B1;

    if (fabs(det) < 1e-12) {
        // No solution
        return 0;
    }

    double x = (C1*B2 - C2*B1) / det;
    double y = (A1*C2 - A2*C1) / det;

    cout << fixed << setprecision(5) << x << " " << y;
    return 0;
}