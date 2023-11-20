#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

// https://codeforces.com/contest/246/problem/E

const int N = 2e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n + 1);
    std::vector<std::vector<int>> adj(n + 1);
    std::vector<std::vector<std::pair<int, int>>> queries(n + 1);
    std::vector<int> dep(n + 1), siz(n + 1), son(n + 1);
    std::vector<std::set<std::string>> st(n * 3);

    for (int i = 1, fa; i <= n; ++i) {
    	std::string s;
    	std::cin >> s >> fa;
    	a[i] = s;
    	adj[fa].emplace_back(i);
    }
    int m;
    std::cin >> m;
    std::vector<int> ans(m);


    for (int i = 0; i < m; ++i) {
    	int k, x;
    	std::cin >> x >> k;
    	queries[x].emplace_back(k, i);
    }

    auto calc = [&](auto &&self, int u, int fa) ->void {
    	siz[u] = 1;
    	dep[u] = dep[fa] + 1;
    	for (auto v : adj[u]) {
    		self(self, v, u);
    		siz[u] += siz[v];
    		if (son[u] == 0 or siz[v] > siz[son[u]]) {
    			son[u] = v;
    		}
    	}
    };
    for (int i : adj[0]) calc(calc, i, 0);

    std::function<void(int)> add = [&](int u) {
    	st[dep[u]].insert(a[u]);
    	for (auto v : adj[u]) {
    		add(v);
    	}
    };

    auto dfs = [&](auto &&self, int u, bool keep) ->void {
    	for (auto v : adj[u]) {
    		if (v != son[u]) {
    			self(self, v, false);
    		}
    	}
    	if (son[u]) self(self, son[u], true);
    	st[dep[u]].insert(a[u]);
    	for (auto v : adj[u]) {
    		if (v != son[u]) {
    			add(v);
    		}		
    	}
    	for (auto[k, index] : queries[u]) {
    		ans[index] = st[dep[u] + k].size();
    	}
    	if (keep) return;
    	for (int i = dep[u]; ; ++i) {
    		if (st[i].size()) st[i].clear();
    		else break;
    	}
    };

    for (auto v : adj[0]) {
    	calc(calc, v, 0);
    }
    for (auto v : adj[0]) {
    	dfs(dfs, v, false);
    }
    for (int i = 0; i < m; ++i) {
    	std::cout << ans[i] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}