#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
    	int a, b;
    	std::cin >> a >> b;
    	a--, b--;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    std::vector dp(1 << n, std::vector<int>(1 << n));
    for (int i = 1; i < 1 << n; i <<= 1) dp[i][i] = 1;
    
    for (int i = 1; i < 1 << n; ++i) {
    	for (int j = i; j > 0; j = (j - 1) & i) {
    		if (dp[i][j]) {
    			for (int u = 0; u < n; ++u) {
    				if (i >> u & 1) {
    					for (auto v : adj[u]) {
    						int now = 0;
    						if (((i >> v) & 1) == 0) {
    							if (__builtin_popcount(i) == 1) {
    								now = i | (1 << v);
    							} else {
                                    //从 j 中去掉 u(如果有的话)
    								now = j & ~(1 << u) | (1 << v);
    							}
    							if (!(now >> (v + 1))) {
    								dp[i | (1 << v)][now] += dp[i][j];
    							}
    						}
    					}
    				}
    			}
    		}
    	}
    } 
    i64 ans = 0;
    for (int i = 0; i < 1 << n; ++i) {
    	if (__builtin_popcount(i) == k) {
    		ans += dp[(1 << n) - 1][i];
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
