#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;
    const int B = std::sqrt(n);
    std::vector<std::vector<int>> adj(n), badj(n);
    for (int i = 0; i < m; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    std::vector<int> big(n), color(n), ans(n);
    for (int i = 0; i < n; ++i) {
    	big[i] = adj[i].size() >= B;
    }
    for (int u = 0; u < n; ++u) {
    	for (auto v : adj[u]) {
    		if (big[v]) {
                // 对于大点 再更新其儿子的时候 就更新其答案
    			badj[u].push_back(v);
    		}
    	}
    }
    for (int i = 0; i < q; ++i) {
    	int op, x;
    	std::cin >> op >> x;
    	--x;
    	if (op == 1) {
    		color[x] ^= 1;
    		for (auto y : badj[x]) {
    			if (color[x]) {
    				ans[y]++;
    			} else {
    				ans[y]--;
    			}
    		}
    	} else {
    		if (big[x]) {
    			std::cout << ans[x] << "\n";
    		} else {
    			int cnt = 0;
    			for (auto y : adj[x]) {
    				cnt += color[y];
    			}
    			std::cout << cnt << "\n";
    		}
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
