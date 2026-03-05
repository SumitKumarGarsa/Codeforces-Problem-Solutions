#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

struct Stadium {
    double x, y, r;
};

Stadium s[3];

double get_error(double x, double y) {
    double d[3];
    for (int i = 0; i < 3; i++) {
        d[i] = hypot(x - s[i].x, y - s[i].y) / s[i].r;
    }

    double e = 0;
    for (int i = 0; i < 3; i++) {
        double diff = d[i] - d[(i + 1) % 3];
        e += diff * diff;
    }

    return e;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    double x = 0, y = 0;

    for (int i = 0; i < 3; i++) {
        cin >> s[i].x >> s[i].y >> s[i].r;
        x += s[i].x;
        y += s[i].y;
    }

    x /= 3.0;
    y /= 3.0;

    double step = 1.0;

    while (step > 1e-6) {
        double best = get_error(x, y);
        double nx = x, ny = y;
        bool moved = false;

        for (int i = 0; i < 8; i++) {
            double ang = i * PI / 4.0;
            double tx = x + cos(ang) * step;
            double ty = y + sin(ang) * step;

            double cur = get_error(tx, ty);

            if (cur < best) {
                best = cur;
                nx = tx;
                ny = ty;
                moved = true;
            }
        }

        if (moved) {
            x = nx;
            y = ny;
        } else {
            step *= 0.5;
        }
    }

    if (get_error(x, y) < 1e-7) {
        cout << fixed << setprecision(5) << x << " " << y;
    }

    return 0;
}
