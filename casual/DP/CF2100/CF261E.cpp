#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 3e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> e(N);
    for (int i = 0; i < m; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	--u, --v;
    	e[w].push_back({u, v});
    }

    // dp[u] 表示按边权小于 w 的走到 u 的最多的边数
    // 但是边权相等的时候会出问题，考虑使用 tmp 数组存储，即 dp 数组不能马上更新
    std::vector<int> dp(n), tmp(n);
    for (int w = 1; w < N; ++w) {
    	for (auto [u, v] : e[w]) {
    		tmp[v] = std::max({tmp[v], dp[v], dp[u] + 1});
    	}
    	for (auto [u, v] : e[w]) {
    		dp[v] = tmp[v];
    	}
    }

    std::cout << std::ranges::max(dp);
}


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
