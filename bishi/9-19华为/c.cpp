#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = -0x3f3f3f3f;

int main() {
    int n, m, c;
    cin >> n >> m >> c;

    unordered_map<int, vector<pair<int, int>>> processes;
    for (int i = 0; i < m * n; i++) {
        int idx, sz, cnt;
        cin >> idx >> sz >> cnt;
        processes[idx].push_back({sz, cnt});
    }

    vector<int> dp(c + 1, INF);
    dp[0] = 0;

    for (auto& proc : processes) {
        vector<int> g(c + 1, INF);
        g[0] = 0;
        for (auto& [sz, cnt] : proc.second) {
            for (int j = c; j >= sz; j--) {
                if (g[j - sz] != INF) {
                    g[j] = max(g[j], g[j - sz] + cnt);
                }
            }
        }
        g[0] = INF;

        vector<int> ndp(c + 1, INF);
        for (int j = 0; j <= c; j++) {
            if (dp[j] != INF) {
                for (int k = 1; j + k <= c; k++) {
                    if (g[k] != INF) {
                        ndp[j + k] = max(ndp[j + k], dp[j] + g[k]);
                    }
                }
            }
        }
        dp = move(ndp);
    }

    int ans = *max_element(dp.begin(), dp.end());
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}
