#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> g[n], d(n), f(n);
    for (int i = 1; i < n; ++i) {
    	std::cin >> f[i];
    	g[--f[i]].push_back(i);
    	d[i] = d[f[i]] + 1;
    }

    std::vector<std::array<int, 3>> path[n];
    for (int i = 0; i < m; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
        --u, --v;
    	int x = u, y = v;
    	while (x != y) {
    		if (d[x] > d[y]) {
    			x = f[x];
    		} else {
    			y = f[y];
    		}
    	}
    	path[x].push_back({u, v, w});
    }
    std::vector<i64> dp(n), sdp(n);

    //dp[i] i这个点为根的子树的最大路径和
    //sdp 儿子的 dp 值之和
    
    std::function<void(int)> dfs = [&](int u) {
    	for (auto v : g[u]) {
    		dfs(v);
    		sdp[u] += dp[v];
    	}
    	dp[u] = sdp[u];
    	for (auto p : path[u]) {
    		i64 t = sdp[u];
    		int x = p[0];
    		while (x != u) {
    			t += sdp[x] - dp[x];
    			x = f[x];
    		}
    		x = p[1];
    		while (x != u) {
    			t += sdp[x] - dp[x];
    			x = f[x];
    		}
    		t += p[2];
    		dp[u] = std::max(dp[u], t);
    	}
    };
    dfs(0);
    std::cout << dp[0];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
