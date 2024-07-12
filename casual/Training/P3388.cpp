#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0, x, y; i < m; ++i) {
    	std::cin >> x >> y;
    	x--, y--;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }

    std::vector<int> dfn(n), low(n);
    int cnt = 0, root = -1;

    std::vector<int> ans;
    auto tarjan = [&](auto &&self, int u, int fa) ->void {
    	dfn[u] = low[u] = ++cnt;
    	int count = 0;
    	for (auto v : adj[u]) {
    		if (v == fa) continue;
    		if (!dfn[v]) {
    			self(self, v, u);
    			low[u] = std::min(low[u], low[v]);
    			if (low[v] >= dfn[u]) {
                    count++;
    				if (u != root or count > 1) {
    				    ans.push_back(u + 1);
                    }
    			}
    		} else {
    			low[u] = std::min(low[u], dfn[v]);
    		}
    	}
    };

    for (int i = 0; i < n; ++i) {
    	if (!dfn[i]) {
            root = i;
            tarjan(tarjan, i, -1);
        }
    }
    std::sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());

    n = ans.size();
    std::cout << n << "\n";
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}