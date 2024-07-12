#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<std::array<int, 2>>> adj(n);
    std::vector<int> st(n);
    for (int i = 0; i < n - 1; ++i) {
    	int u, v, op;
    	std::cin >> u >> v >> op;
    	--u, --v;
    	adj[u].push_back({v, op});
    	adj[v].push_back({u, op});
    }	
    std::vector<int> ans;
    std::function<bool(int, int)> dfs = [&](int u, int fa) {
		bool choose = false;
		for (auto [v, op] : adj[u]) {
			if (v != fa) {
				bool c = dfs(v, u);
				if (!c and op == 2) {
					ans.push_back(v);
					c = true;
				}
				choose = choose || c;
			}
		}
		return choose;
    };
    dfs(0, -1);
    std::cout << ans.size() << "\n";
    for (int x : ans) {
    	std::cout << ++x << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
