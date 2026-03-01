#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<string, int>> rounds(n);
    map<string, int> final_score;

    for (int i = 0; i < n; i++) {
        cin >> rounds[i].first >> rounds[i].second;
        final_score[rounds[i].first] += rounds[i].second;
    }

    // Find maximum final score
    int max_score = INT_MIN;
    for (auto &p : final_score) {
        max_score = max(max_score, p.second);
    }

    // Find winner by replaying rounds
    map<string, int> current_score;

    for (int i = 0; i < n; i++) {
        string name = rounds[i].first;
        int score = rounds[i].second;

        current_score[name] += score;

        if (current_score[name] >= max_score && 
            final_score[name] == max_score) {
            cout << name << "\n";
            break;
        }
    }

    return 0;
}