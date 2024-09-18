#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    std::vector<int> vis(n);

    for (int i = 0; i < m; ++i) {
    	int v, u;
    	std::cin >> u >> v;
    	--v, --u;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    q.push(0);
    vis[0] = 1;

    while (!q.empty()) {
    	int u = q.top();
    	q.pop();
        std::cout << u + 1 << " ";

    	for (auto v : adj[u]) {
    		if (!vis[v]) {
    			q.push(v);
                // vis[v] = 1 要在这里 因为存在重边
                vis[v] = true;
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
