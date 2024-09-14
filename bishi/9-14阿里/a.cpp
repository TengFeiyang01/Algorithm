#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, t;
    std::cin >> n >> m >> t;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    std::queue<int> q;
    std::vector<int> dist(n, -1), cnt(n);
    for (int i = 0; i < t; ++i) {
    	int x;
    	std::cin >> x;
    	dist[x - 1] = 0;
    	q.push(x - 1);
    }

    while (q.size()) {
    	int u = q.front();
    	q.pop();
    	for (auto v : adj[u]) {
    		if (dist[v] == -1) {
    			dist[v] = dist[u] + 1;
    			q.push(v);
    		} 
    		if (dist[v] >= dist[u]) {
    			cnt[v]++;
    		}
    	}
    }
    for (int i = 0; i < n; ++i) {
    	if (cnt[i] == adj[i].size() and dist[i] != -1) {
            std::cout << i + 1 << " ";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
