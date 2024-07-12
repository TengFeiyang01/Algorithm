#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> adj(n);
    std::vector<int> d(n), st(n);
    for (int i = 0; i < n - 1; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    	d[u]++;
    	d[v]++;
    }
    std::queue<int> q;
    for (int i = 0; i < n; ++i) {
    	if (d[i] <= 1) {
    		q.push(i);
    	}
    }

    for (int i = 0; i < k; ++i) {
        int len = q.size();
        for (int j = 0; j < len; ++j) {
            int u = q.front();
            q.pop();
            st[u] = 1;
            for (auto v : adj[u]) {
                if (d[v]) {
                    --d[v];
                    --d[u];
                    if (d[v] == 1) {
                        q.push(v);
                    }
                }
            }
        }
    }    
    std::cout << std::ranges::count(st, 0) << "\n";
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
