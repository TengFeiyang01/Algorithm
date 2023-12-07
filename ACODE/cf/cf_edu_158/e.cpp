#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    std::vector<i64> dp(n);
    i64 ans = 0;


    // 我们考虑dp[i]为以i的子树中不会再被压缩，在连接了i的父亲节点后也不会再被压缩
    std::function<void(int, int)> dfs = [&](int u, int fa) {
    	dp[u] = a[u];
    	ans = std::max(ans, a[u]);
    	std::vector<i64> pos, neg;
    	for (auto v : adj[u]) {
    		if (v != fa) {
    			dfs(v, u);
    			dp[u] = std::max(dp[u], dp[v]);  // dp[u] 用来计算dp[v] 此时u被忽略 在fa和v连边 使用dp[v]代替dp[u]
    			ans = std::max(ans, dp[v] + a[u]);  // 只保留u及其一个子树且此时不会被压缩
    			if (dp[v] >= 0) pos.push_back(dp[v]); 
    			else neg.push_back(dp[v]);
    		}
    	}
    	std::ranges::sort(pos);
    	std::ranges::sort(neg);

    	int x = pos.size(), y = neg.size();
    	if (x > 1) {
    		i64 s = std::accumulate(pos.begin(), pos.end(), a[u]);  
    		dp[u] = std::max(dp[u], s);  // 计算dp值时 保留所有dp值大于0的子树 此时u也要保留
    		ans = std::max(ans, pos[x - 1] + pos[x - 2]);  // 仅保留当前结点的最大的两个儿子
    		if (x > 2) {
    			ans = std::max(ans, s);  // 只计算u及其大于0的子树
    		}
    	} 
    	if (x == 2 and y) {
    		ans = std::max(ans, pos[x - 1] + pos[x - 2] + a[u] + neg.back());  // 保留两个最大的正的 一个最大的负的 此时可以保留a[u]
    	}
    	if (x == 1 and y) {
    		dp[u] = std::max(dp[u], a[u] + pos.back() + neg.back());  // 保留u时 需要保证u至少连接两个儿子  
    		ans = std::max(ans, pos.back() + neg.back());  // 只保留一个最大 一个最小 删去u
    	}
    };
    dfs(0, -1);
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
