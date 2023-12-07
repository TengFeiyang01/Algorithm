#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 1e5 + 13;

std::vector<int> adj[N];
int n, q, tot = 0;
int top[N], id[N], siz[N], hs[N]{0}, dep[N], fa[N], w[N], nw[N];

void dfs1(int u, int p) {
	dep[u] = dep[p] + 1;
	siz[u] = 1;
	fa[u] = p;
	for (auto v : adj[u]) {
		if (v != p) {
			dfs1(v, u);
			siz[u] += siz[v];
			if (!hs[u] or siz[hs[u]] < siz[v]) {
				hs[u] = v;
			}
		}
	}
}

void dfs2(int u, int t) {
	top[u] = t;
	id[u] = ++tot;
	if (hs[u]) dfs2(hs[u], t);
	for (auto v : adj[u]) {
		if (v != fa[u] and v != hs[u]) {
			dfs2(v, v);
		}
	}
}

struct node {
	int mx = -inf;
	int sum = 0;
}tr[N << 2];

node operator+(const node &a, const node &b) {
	node ans;
	ans.mx = std::max(a.mx, b.mx);
	ans.sum = a.sum + b.sum;
	return ans;
}

void pull(int o) {
	tr[o] = tr[o << 1] + tr[o << 1 | 1];
}

void update(int o, int l, int r, int pos, int val) {
	if (l == r) {
		tr[o].sum = tr[o].mx = val;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) update(o << 1, l, mid, pos, val);
	else update(o << 1 | 1, mid + 1, r, pos, val);
	pull(o);
}

node query(int o, int l, int r, int ql, int qr) {
	if (ql <= l and r <= qr) {
		return tr[o];
	}
	int mid = (l + r) >> 1;
	node ans;
	if (ql <= mid) ans = query(o << 1, l, mid, ql, qr);
	if (qr > mid) ans = ans + query(o << 1 | 1, mid + 1, r, ql, qr);
	return ans;
}

node query_path(int u, int v) {
	node ans;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
		ans = ans + query(1, 1, n, id[top[u]], id[u]);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) std::swap(u, v);
	ans = ans + query(1, 1, n, id[v], id[u]);
	return ans;
}


// nlognlogn
void solve() {
    std::cin >> n;
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
    	std::cin >> w[i];
    }
    dfs1(1, 0);
    dfs2(1, 1);

    for (int i = 1; i <= n; ++i) {
    	update(1, 1, n, id[i], w[i]);
    }

    std::string op;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
    	int u, v, t;
    	std::cin >> op;
    	if (op == "CHANGE") {
    		std::cin >> u >> t;
    		w[u] = t;
    		update(1, 1, n, id[u], w[u]);
    	} else if (op == "QMAX") {
    		std::cin >> u >> v;
    		std::cout << query_path(u, v).mx << "\n";
    	} else {
    		std::cin >> u >> v;
    		std::cout << query_path(u, v).sum << "\n";
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
