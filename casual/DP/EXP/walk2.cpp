#include <bits/stdc++.h>

constexpr int mod = 1e9 + 7;

long long qpow(long long x, int y) {
    long long res = 1;
    for (; y; y /= 2, x *= x, x %= mod)
        if (y & 1)
            res *= x, res %= mod;
    return res;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> g[n];
    std::vector<long long> dp(n);
    for (int i = 0; i < m; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	g[x - 1].emplace_back(y - 1);
    }
    dp[0] = 1;
    for (int i = 0; i < n - 1; ++i) {
        int l = g[i].size();
    	for (auto j : g[i]) {
            dp[j] += 1LL * dp[i] * qpow(l, mod - 2);
            dp[j] %= mod;
        }
    }
    std::cout << dp[n - 1];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
