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
	nw[tot] = w[u];
	if (hs[u]) dfs2(hs[u], t);
	for (auto v : adj[u]) {
		if (v != fa[u] and v != hs[u]) {
			dfs2(v, v);
		}
	}
}

struct info {
	int lc, rc, seg;
};

struct node {
	info val;
	int tag;
}tr[N << 2];

info operator+(const info &a, const info &b) {
	return (info){a.lc, b.rc, a.seg + b.seg - (a.rc == b.lc)};
}

void pull(int o) {
	tr[o].val = tr[o << 1].val + tr[o << 1 | 1].val;
}

void setTag(int o, int t) {
	tr[o].val = (info){t, t, 1};
	tr[o].tag = t;
}

void push(int o) {
	if (tr[o].tag) {
		setTag(o << 1, tr[o].tag);
		setTag(o << 1 | 1, tr[o].tag);
		tr[o].tag = 0;
	}
}

void build(int o, int l, int r) {
	if (l == r) {
		tr[o].val = (info){nw[l], nw[r], 1};
		return;
	}
	int mid = (l + r) >> 1;
	build(o << 1, l, mid);
	build(o << 1 | 1, mid + 1, r);
	pull(o);
}

void rangeUpdate(int o, int l, int r, int ql, int qr, int c) {
	if (ql <= l and r <= qr) {
		setTag(o, c);
		return;
	}
	int mid = (l + r) >> 1;
	push(o);
	if (ql <= mid) rangeUpdate(o << 1, l, mid, ql, qr, c);
	if (qr > mid) rangeUpdate(o << 1 | 1, mid + 1, r, ql, qr, c);
	pull(o);
}

info query(int o, int l, int r, int ql, int qr) {
	if (ql <= l and r <= qr) {
		return tr[o].val;
	}
	push(o);
	int mid = (l + r) >> 1;
	if (qr <= mid) return query(o << 1, l, mid, ql, qr);
	else if (ql > mid) return query(o << 1 | 1, mid + 1, r, ql, qr);
	else return query(o << 1, l, mid, ql, qr) + query(o << 1 | 1, mid + 1, r, ql, qr);
}

//需要区分左右儿子
int query_path(int u, int v) {
	info ansv{0, 0, 0}, ansu{0, 0, 0};
	while (top[u] != top[v]) {
		if (dep[top[u]] >= dep[top[v]]) {
			ansu = query(1, 1, n, id[top[u]], id[u]) + ansu;
			u = fa[top[u]];
		} else {
			ansv = query(1, 1, n, id[top[v]], id[v]) + ansv;
			v = fa[top[v]];
		}
	}
	if (dep[u] >= dep[v]) {
		ansu = query(1, 1, n, id[v], id[u]) + ansu;
	} else {
		ansv = query(1, 1, n, id[u], id[v]) + ansv;
	}
	return ansu.seg + ansv.seg - (ansu.lc == ansv.lc);
}

void modify_path(int u, int v, int c) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
		rangeUpdate(1, 1, n, id[top[u]], id[u], c);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) std::swap(u, v);
	rangeUpdate(1, 1, n, id[v], id[u], c);
}


// nlognlogn
void solve() {
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> w[i];
    }

    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);

    std::string op;
    for (int i = 0; i < q; ++i) {
    	int u, v, t;
    	std::cin >> op;
    	if (op == "C") {
    		int u, v, c;
    		std::cin >> u >> v >> c;
    		modify_path(u, v, c);
    	} else {
    		int u, v;
    		std::cin >> u >> v;
    		std::cout << query_path(u, v) << "\n";
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
} 