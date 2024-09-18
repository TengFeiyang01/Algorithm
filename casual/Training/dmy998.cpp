#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
        // xu - xv <= k === xv - xu >= -k
    	adj[u].emplace_back(v, -w);
    }
    for (int i = 1; i <= n; ++i) {
    	adj[0].emplace_back(i, 0);
    }

    // xi - x0 >= 0
    std::vector<int> dist(n + 1, -inf);
    dist[0] = 0;
    std::queue<int> q;
    q.push(0);
    std::vector<int> cnt(n + 1), st(n + 1);
    bool ok = true;
    st[0] = 1;

    while (!q.empty()) {
    	int u = q.front();
    	if (cnt[u] > n + 1) {
    		ok = false;
            break;
    	}
    	q.pop();
    	st[u] = 0;

    	for (auto [v, w] : adj[u]) {
    		if (dist[v] < dist[u] + w) {
    			dist[v] = dist[u] + w;
    			if (!st[v]) {
    				q.push(v);
    				st[v] = true;
    				cnt[v]++;
    			}
    		}
    	}
    }
    
    if (!ok) {
    	std::cout << "-1\n";
    } else {
    	for (int i = 1; i <= n; ++i) {
    		std::cout << dist[i] << " \n"[i == n];
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
