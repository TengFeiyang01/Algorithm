#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> adj[n];
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	adj[u - 1].push_back(v - 1);
    	adj[v - 1].push_back(u - 1);
    }
    if (k == 2) {
    	std::cout << (n - 1LL) * n / 2 % MOD << "\n";
        return;
    }

    std::vector<i64> dp(n + 1);
    i64 cnt = 0, ans = 0;
    std::function<void(int, int, int)> dfs = [&](int u, int fa, int d) {
    	if (d == 0) {
    		cnt++;
    		return;
    	}
    	for (auto &v : adj[u]) {
    		if (v == fa) continue;
    		dfs(v, u, d - 1);
    	}
    };

    for (int i = 0; i < n; ++i) {
    	for (int d = 1; d <= n; ++d) {
    		std::fill(dp.begin(), dp.end(), 0);
    		dp[0] = 1;
    		for (auto v : adj[i]) {
    			cnt = 0; 
    			dfs(v, i, d - 1);
    			for (int j = k; j >= 1; --j)
    				dp[j] = (cnt * dp[j - 1] + dp[j]) % MOD;
    		}
			ans = (ans + dp[k]) % MOD;    		
    	}
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
