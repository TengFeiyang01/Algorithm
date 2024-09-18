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
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    //给你树 删除一些边使得除了s之外的叶子结点都不能到s
    int n, m, s;
    std::cin >> n >> m >> s;
    std::vector<PII> g[n];
    for (int i = 1; i < n; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	--u, --v;
    	g[u].emplace_back(v, w);
    	g[v].emplace_back(u, w);
    }
    std::vector<int> dp(n);

    std::function<void(int, int)> dfs = [&](int u, int p) {
    	int ans = 0;
    	for (auto [v, w] : g[u]) {
    		if (v == p) continue;
    		dfs(v, u);
    		ans += std::min(dp[v], w);
    	}
    	if (ans == 0) {
    		dp[u] = inf;
    	} else {
    		dp[u] = ans;
    	}
    };
    dfs(s - 1, -1);
    std::cout << dp[s - 1] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
