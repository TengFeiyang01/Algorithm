#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int y, i = 0; i < n; ++i) {
    	while (std::cin >> y, y) {
    		adj[i].push_back(y - 1);
    	}
    }

    int idx = 0, cnt = 0;
    std::vector<bool> st(n);
    std::stack<int> stk;
    std::vector<int> ind(n + 1), outd(n + 1), dfn(n), low(n), id(n);

    auto tarjan = [&](auto &&self, int u) -> void {	
    	dfn[u] = low[u] = ++idx;
    	stk.push(u);
    	st[u] = true;
    	for (auto &v : adj[u]) {
    		if (!dfn[v]) {
    			self(self, v);
    			low[u] = std::min(low[u], low[v]);
    		} else if (st[v]) {
    			low[u] = std::min(low[u], dfn[v]);
    		}
    	}

    	if (dfn[u] == low[u]) {
    		++cnt;
    		int y;
    		do {
    			y = stk.top();
    			stk.pop();
    			st[y] = false;
    			id[y] = cnt;

    		} while (y != u);
    	}
    };
    int p = 0, q = 0;

    for (int i = 0; i < n; ++i) {
    	if (!dfn[i]) {
    		tarjan(tarjan, i);
    	}
    }
    
    for (int u = 0; u < n; ++u) {
    	for (auto &v : adj[u]) {
    		if (id[u] != id[v]) {
    			outd[id[u]]++;
    			ind[id[v]]++;
    		}
    	}
    }

    int zero = 0, sum = 0;
    for (int i = 1; i <= cnt; ++i) {
    	if (!outd[i]) {
    		q++;
    	}
    	if (!ind[i]) {
    		p++;
    	}
    }
    std::cout << p << "\n";
    std::cout << (cnt == 1 ? 0 : std::max(p, q)) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}