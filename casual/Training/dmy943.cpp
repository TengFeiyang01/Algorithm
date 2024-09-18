#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, idx, cnt;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n), radj(n), scc;

    std::vector<int> dfn(n), low(n), ins(n), bel(n);
    std::stack<int> stk;

    for (int i = 0; i < m; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].emplace_back(v);
        radj[v].emplace_back(u);
    }

    std::vector<int> out, st(n);

    std::function<void(int)> dfs = [&](int u) {
        st[u] = true;
        for (auto &v : adj[u]) {
            if (!st[v]) {
                dfs(v);            }
        }
        out.emplace_back(u);
    };
    std::vector<int> c;

    std::function<void(int)> rdfs = [&](int u) {
        st[u] = true;
        c.emplace_back(u);
        for (auto &v : radj[u]) {
            if (!st[v]) {
                rdfs(v);            
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!st[i]) {
            dfs(i);
        }
    }

    std::reverse(out.begin(), out.end());
    
    st.assign(n, 0);
    
    for (int i : out) {
        if (!st[i]) {
            c.clear();
            rdfs(i);
            std::sort(c.begin(), c.end());
            scc.emplace_back(c);
        }
    }

   /* std::function<void(int)> tarjan = [&](int u) {
    	dfn[u] = low[u] = ++idx;
    	ins[u] = true;
    	stk.push(u);
    	for (const int &v : adj[u]) {
    		if (!dfn[v]) {
    			tarjan(v);
    			low[u] = std::min(low[u], low[v]);
    		} else {
    			if (ins[v]) {
	    			low[u] = std::min(low[u], dfn[v]);
    			}
    		}
    	}

    	if (dfn[u] == low[u]) {
    		std::vector<int> c;
            ++cnt;
            while (true) {
                int v = stk.top();
                ins[v] = false;
                stk.pop();
                c.push_back(v);
                bel[v] = cnt;
                if (v == u) break;
            }

    		std::sort(c.begin(), c.end());
    		scc.emplace_back(c);
    	}
    };

    for (int i = 0; i < n; ++i) {
    	if (!dfn[i]) {
    		tarjan(i);
    	}
    }
    */
    std::sort(scc.begin(), scc.end());
    for (const auto &c : scc) {
    	for (auto v : c) {
    		std::cout << v + 1 << " ";
    	}
    	std::cout << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}