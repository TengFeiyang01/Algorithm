#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    std::vector<int> d(n);
    for (int i = 0; i < m; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	--x, --y;
    	adj[x].push_back(y);
    	d[y]++;
    }
    std::vector<int> dp(n);
    std::queue<int> q;
    for (int i = 0; i < n; ++i) {
    	if (d[i] == 0) {
    		q.push(i);
    	}
    }

    int ans = 0;

    while (q.size()) {
    	int u = q.front();
    	q.pop();
  		ans = std::max(ans, dp[u]);

    	for (auto &v : adj[u]) {
    		if (--d[v] == 0) {
    			q.push(v);
    			dp[v] = std::max(dp[u] + 1, dp[v]);
    		}
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
	