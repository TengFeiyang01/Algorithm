#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int md = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    std::vector<int> siz(n);

    i64 ans = 1;

    std::function<void(int, int)> dfs1 = [&](int u, int fa) ->void {
    	siz[u] = 1;
    	int cnt = 0;
    	for (auto v : adj[u]) {
            if (v == fa) continue;
            dfs1(v, u);
    		siz[u] += siz[v];
    		// v 有偶数条边 说明自匹配完了  此时u->v这条边可以在u这里匹配 
    		if (siz[v] % 2 == 1) cnt += 1; 
    	}
        // 如果伸下去的是奇数条 需要将父亲的考虑在内
        if (cnt % 2 == 1) cnt += 1;
        for (int i = cnt - 1; i >= 1; i -= 2) {
            ans = ans * i % md;
        }
    };

    dfs1(0, -1);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
