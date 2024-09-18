#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 1e5 + 13;

int siz[N], top[N], l[N], r[N], dep[N], hs[N], fa[N], id[N << 1];
int n, q, tot = 0;
std::vector<int> adj[N];

void dfs1(int u, int p) {
	siz[u] = 1;
	hs[u] = -1;
	fa[u] = p;
	dep[u] = dep[p] + 1;
	for (auto v : adj[u]) {
		if (v != p) {
			dfs1(v, u);
			siz[u] += siz[v];
			if (hs[u] == -1 or siz[hs[u]] < siz[v]) {
				hs[u] = v;
			}
		}
	}
}

void dfs2(int u, int t) {
	top[u] = t;
	l[u] = ++tot;
	id[tot] = u;
	if (hs[u] != -1) dfs2(hs[u], t);
	for (auto v : adj[u]) {
		if (v != fa[u] and v != hs[u]) {
			dfs2(v, v);
		}
	}
	r[u] = tot;
}

int LCA(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) v = fa[top[v]];
		else u = fa[top[u]];
	}
	if (dep[u] < dep[v]) return u;
	else return v;
}

void solve() {
	std::cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	std::cin >> q;
	dfs1(1, 0);
	dfs2(1, 1);
	for (int i = 0; i < q; ++i) {
		int u, v;
		std::cin >> u >> v;
		std::cout << LCA(u, v) << "\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
