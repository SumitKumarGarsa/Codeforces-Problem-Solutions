#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int x1 = s[0] - 'a';
    int y1 = s[1] - '1';
    int x2 = t[0] - 'a';
    int y2 = t[1] - '1';

    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);

    cout << max(dx, dy) << endl;

    while (x1 != x2 || y1 != y2) {
        string move = "";

        if (x1 < x2) {
            move += "R";
            x1++;
        } else if (x1 > x2) {
            move += "L";
            x1--;
        }

        if (y1 < y2) {
            move += "U";
            y1++;
        } else if (y1 > y2) {
            move += "D";
            y1--;
        }

        cout << move << endl;
    }

    return 0;
}
