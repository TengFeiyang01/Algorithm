#include <bits/stdc++.h>

const double inf = 1e27;
using i64 = long long;

void solve() {
    int n, d;
    std::cin >> n >> d;
    std::vector<int> a(n);
    double avg = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	avg += a[i];
    }
    avg /= d;
    std::vector<double> cost(1 << n);
    for (int t = 0; t < 1 << n; ++t) {
        int now = 0;
        for (int i = 0; i < n; ++i) {
            if (t & (1 << i)) {
                now += a[i];
            }
        }
        cost[t] = (now - avg) * (now - avg);
    }

    std::vector<double> dp(1 << n, inf);
    dp[0] = 0;
    // 做d次dp 每次代表一个划分子集
    for (int i = 0; i < d; ++i) {
        std::vector<double> ndp(1 << n, inf);
        for (int t = 0; t < 1 << n; ++t) {
            int u = t;
            while (true) {
                ndp[t] = std::min(ndp[t], dp[u] + cost[t ^ u]);
                if (u == 0) break;
                // 枚举子集
                u = (u - 1) & t;
            }
        }
        std::swap(dp, ndp);
    }
    std::cout << std::fixed << std::setprecision(17) << dp.back() / d << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}

