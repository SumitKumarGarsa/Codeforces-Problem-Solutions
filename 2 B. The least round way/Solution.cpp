#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> dp2(n, vector<int>(n, INF));
    vector<vector<int>> dp5(n, vector<int>(n, INF));
    vector<vector<char>> path2(n, vector<char>(n));
    vector<vector<char>> path5(n, vector<char>(n));

    int zero_row = -1, zero_col = -1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0) {
                zero_row = i;
                zero_col = j;
                a[i][j] = 1; // Treat zero as 1 temporarily
            }
        }
    }

    auto count_factor = [](int x, int factor) {
        int cnt = 0;
        while(x % factor == 0) {
            x /= factor;
            cnt++;
        }
        return cnt;
    };

    dp2[0][0] = count_factor(a[0][0], 2);
    dp5[0][0] = count_factor(a[0][0], 5);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) continue;

            int c2 = count_factor(a[i][j], 2);
            int c5 = count_factor(a[i][j], 5);

            if(i > 0) {
                if(dp2[i][j] > dp2[i-1][j] + c2) {
                    dp2[i][j] = dp2[i-1][j] + c2;
                    path2[i][j] = 'D';
                }
                if(dp5[i][j] > dp5[i-1][j] + c5) {
                    dp5[i][j] = dp5[i-1][j] + c5;
                    path5[i][j] = 'D';
                }
            }

            if(j > 0) {
                if(dp2[i][j] > dp2[i][j-1] + c2) {
                    dp2[i][j] = dp2[i][j-1] + c2;
                    path2[i][j] = 'R';
                }
                if(dp5[i][j] > dp5[i][j-1] + c5) {
                    dp5[i][j] = dp5[i][j-1] + c5;
                    path5[i][j] = 'R';
                }
            }
        }
    }

    int result = min(dp2[n-1][n-1], dp5[n-1][n-1]);

    // If using zero gives better result
    if(zero_row != -1 && result > 1) {
        cout << 1 << "\n";
        for(int i = 0; i < zero_row; i++) cout << "D";
        for(int j = 0; j < zero_col; j++) cout << "R";
        for(int i = zero_row; i < n-1; i++) cout << "D";
        for(int j = zero_col; j < n-1; j++) cout << "R";
        cout << "\n";
        return 0;
    }

    cout << result << "\n";

    // Reconstruct path
    string path = "";
    int i = n-1, j = n-1;

    if(dp2[n-1][n-1] < dp5[n-1][n-1]) {
        while(i > 0 || j > 0) {
            path += path2[i][j];
            if(path2[i][j] == 'D') i--;
            else j--;
        }
    } else {
        while(i > 0 || j > 0) {
            path += path5[i][j];
            if(path5[i][j] == 'D') i--;
            else j--;
        }
    }

    reverse(path.begin(), path.end());
    cout << path << "\n";

    return 0;
}