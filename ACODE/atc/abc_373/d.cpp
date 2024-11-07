#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<std::pair<int, i64>>> adj(N);
    for (int i = 0; i < M; ++i) {
    	int u, v;
    	i64 w;
    	std::cin >> u >> v >> w;
    	adj[u - 1].emplace_back(v - 1, w);
    	adj[v - 1].emplace_back(u - 1, -w);
    } 

    std::vector<i64> ans(N);
    std::vector<bool> st(N);
    auto dfs = [&](auto &&self, int u) -> void {
    	for (auto [v, w] : adj[u]) {
    		if (!st[v]) {
    			st[v] = 1;
    			ans[v] = ans[u] + w;
    			self(self, v);
    		}
    	}
    };
    for (int i = 0; i < N; ++i) {
    	if (!st[i]) {
    		st[i] = 1;
    		ans[i] = 0;
    		dfs(dfs, i);
    	}
    }
    for (int i = 0; i < N; ++i) {
    	std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
