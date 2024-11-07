#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<long long> solve(const vector<pair<int, int>>& items, int limit) {
    vector<long long> dp(limit + 1, 0);
    for (const auto& item : items) {
        vector<long long> dp2(limit + 1, 0);
        int weight = item.first;
        int count = item.second;

        for (int j = 0; j <= limit; j++) {
            dp2[j] = max(dp2[j], dp[j]);
            if (j + weight <= limit) {
                dp2[j + weight] = max(dp2[j + weight], dp[j] + count);
            }
        }
        dp = dp2;
    }
    return dp;
}

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<pair<int, int>>> packs(n);

    for (int i = 0; i < n * m; i++) {
        int pid, weight, count;
        cin >> pid >> weight >> count;
        packs[pid].push_back({weight, count});
    }

    long long inf = LLONG_MIN / 10;
    vector<long long> dp(c + 1, inf);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        vector<long long> dp2(c + 1, inf);
        vector<long long> ws = solve(packs[i], c);

        for (int j = 1; j <= c; j++) {
            if (ws[j] == 0) continue;
            for (int k = 0; k <= c - j; k++) {
                if (dp[k] == inf) continue;
                dp2[k + j] = max(dp2[k + j], dp[k] + ws[j]);
            }
        }
        dp = dp2;
    }
    long long res = *max_element(dp.begin(), dp.end());
    if (res == inf) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }

    return 0;
}
