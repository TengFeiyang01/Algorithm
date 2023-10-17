#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    for (int x, y, i = 0; i < m; ++i) {
    	std::cin >> x >> y;
    	adj[x - 1].push_back(y - 1);
    }

    int idx = 0, cnt = 0;
    std::vector<bool> st(n);
    std::stack<int> stk;
    std::vector<int> ind(n), siz(n), outd(n), dfn(n), low(n), id(n);

    std::function<void(int)> tarjan = [&](int u) -> void {	
    	dfn[u] = low[u] = ++idx;
    	stk.push(u);
    	st[u] = true;
    	for (auto &v : adj[u]) {
    		if (!dfn[v]) {
    			tarjan(v);
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
    			siz[cnt]++;

    		} while (y != u);
    	}
    };
    for (int i = 0; i < n; ++i) {
    	if (!dfn[i]) {
    		tarjan(i);
    	}
    }
    for (int u = 0; u < n; ++u) {
    	for (auto &v : adj[u]) {
    		if (id[u] != id[v]) {
    			outd[id[u]]++;
    		}
    	}
    }
    int zero = 0, sum = 0;
    for (int i = 1; i <= cnt; ++i) {
    	if (!outd[i]) {
    		zero++;
    		sum += siz[i];
    		if (zero > 1) {
    			sum = 0;
    			break;
    		}
    	}
    }
    std::cout << sum << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}