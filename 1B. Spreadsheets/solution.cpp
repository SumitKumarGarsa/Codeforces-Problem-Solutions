#include <iostream>
#include <string>
using namespace std;

bool isRxCy(const string &s) {
    if (s[0] != 'R') return false;

    int i = 1;
    while (i < s.size() && isdigit(s[i])) i++;

    if (i == 1 || i >= s.size() || s[i] != 'C') return false;

    i++; 
    if (i >= s.size()) return false;

    while (i < s.size()) {
        if (!isdigit(s[i])) return false;
        i++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        if (isRxCy(s)) {
            // Convert RxCy -> Letters+Number
            int i = 1;
            long long row = 0;
            while (isdigit(s[i])) {
                row = row * 10 + (s[i] - '0');
                i++;
            }

            i++; // skip 'C'

            long long col = 0;
            while (i < s.size()) {
                col = col * 10 + (s[i] - '0');
                i++;
            }

            string colStr = "";
            while (col > 0) {
                col--;
                colStr = char('A' + (col % 26)) + colStr;
                col /= 26;
            }

            cout << colStr << row << "\n";
        } else {
            // Convert Letters+Number -> RxCy
            int i = 0;
            long long col = 0;

            while (i < s.size() && isalpha(s[i])) {
                col = col * 26 + (s[i] - 'A' + 1);
                i++;
            }

            long long row = 0;
            while (i < s.size()) {
                row = row * 10 + (s[i] - '0');
                i++;
            }

            cout << "R" << row << "C" << col << "\n";
        }
    }

    return 0;
}