#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 inf = 1e18;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
using std::vector;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> adj[n], a(n), siz(n);
    for (int i = 1; i < n; ++i) {
    	int fa;
    	std::cin >> fa;
    	adj[fa - 1].push_back(i);
    }

    for (int i = 0; i < n; ++i) std::cin >> a[i];

    vector<vector<vector<i64>>> dp(n, vector<vector<i64>>(2, vector<i64>(2)));
    
    //dp[i][j][0/1] 以u为根的子树 使用了 j 次魔法，且 u 这个点 没有/有 使用魔法的最小花费

    std::function<void(int)> dfs = [&](int u) {
    	siz[u] = 1;
    	dp[u][0][0] = a[u];
    	dp[u][1][0] = inf;
    	dp[u][0][1] = inf;
    	dp[u][1][1] = 0;
    	for (auto &v : adj[u]) {
    		dfs(v);
			vector<vector<i64>> tmp(siz[u] + siz[v] + 1, vector<i64>(2, inf));
    		for (int i = 0; i <= siz[u]; ++i)
    			for (int j = 0; j <= siz[v]; ++j) {
    				tmp[i + j][0] = std::min(tmp[i + j][0], dp[u][i][0] + std::min(dp[v][j][0] + a[v], dp[v][j][1]));
    				tmp[i + j][1] = std::min(tmp[i + j][1], dp[u][i][1] + std::min(dp[v][j][1], dp[v][j][0]));
    			}
    		dp[u] = tmp;
    		siz[u] += siz[v];
    	}
    };
    dfs(0);

    for (int i = 0; i <= n; ++i) {
    	std::cout << std::min(dp[0][i][0], dp[0][i][1]) << " \n"[i == n];
    }
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
