#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> c(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> c[i].first;
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> c[i].second;
    }
    i64 ans = 0;
    std::sort(c.begin(), c.end());
    std::vector<int> cnt(n + 1);
    //b_i + b_j = a_i * a_j
    //b_i = s * a_j - b_j
    //统计当a_i == s 对于的b_i的个数
    for (int s = 1; s * s <= 2 * n; ++s) {
        cnt.assign(n + 1, 0);
        for (auto &[a, b] : c) {
            int v = a * s - b;
            if (1 <= v and v <= n) {
                ans += cnt[v];
            }
            if (a == s) {
                cnt[b]++;
            }
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
