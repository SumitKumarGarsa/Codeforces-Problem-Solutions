#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-6;
const double PI = acos(-1.0);

double dist(pair<double,double> a, pair<double,double> b) {
    return hypot(a.first - b.first, a.second - b.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<double,double> A, B, C;
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    cin >> C.first >> C.second;

    double a = dist(B, C);
    double b = dist(A, C);
    double c = dist(A, B);

    // Heron's formula for triangle area
    double s = (a + b + c) / 2.0;
    double area_triangle = sqrt(s * (s - a) * (s - b) * (s - c));

    // Circumradius
    double R = a * b * c / (4.0 * area_triangle);

    // Angles of triangle using Law of Cosines
    double alpha = acos((b*b + c*c - a*a) / (2.0*b*c));
    double beta  = acos((a*a + c*c - b*b) / (2.0*a*c));
    double gamma = PI - alpha - beta;

    vector<double> angles = {alpha, beta, gamma};

    int n;
    for (n = 3; n <= 100; n++) {
        bool ok = true;
        double unit = PI / n;
        for (double angle : angles) {
            double k = round(angle / unit);
            if (fabs(angle - k * unit) > EPS) {
                ok = false;
                break;
            }
        }
        if (ok) break;
    }

    // Area of regular n-gon with circumradius R
    double area_polygon = n * R * R * sin(2.0 * PI / n) / 2.0;

    cout << fixed << setprecision(7) << area_polygon << "\n";

    return 0;
}