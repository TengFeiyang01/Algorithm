#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 1e5 + 13;

std::map<int, int> dp[N];

void add(int v, int w, int y) {
	for (w; w < N; w += w & -w) {
		dp[v][w] = std::max(dp[v][w], y);
	}
}

int query(int u, int w) {
	int ans = 0;
	while (w) {
		if (dp[u].count(w)) {
			ans = std::max(ans, dp[u][w]);
		}
		w &= w - 1;
	}
	return ans;
}

void solve() {
	int n, m, ans = 0;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	++w;
    	// int mx = query(root[u], 0, N, w - 1);
    	int mx = query(u, w - 1);
    	add(v, w, mx + 1);
    	ans = std::max(ans, mx + 1);
    	// insert(root[v], 0, N, w, mx + 1);
    }
    std::cout << ans << "\n";
}

/*int root[N], val[N * 21], ls[N * 21], rs[N * 21], idx = 0;

void insert(int &id, int l, int r, int w, int num) {
	if (id == 0) id = ++idx;
	val[id] = std::max(val[id], num);
	if (l == r) return;
	int mid = l + r >> 1;
	if (w <= mid) insert(ls[id], l, mid, w, num);
	else insert(rs[id], mid + 1, r, w, num);
}

i64 query(int id, int l, int r, int k) {
	if (id == 0 || l > k) return 0;
	if (r <= k) return val[id];
	int mid = l + r >> 1;
	return std::max(query(ls[id], l, mid, k), query(rs[id], mid + 1, r, k));
}

void solve() {
    int n, m, ans = 0;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	int mx = query(root[u], 0, N, w - 1);
    	ans = std::max(ans, mx + 1);
    	insert(root[v], 0, N, w, mx + 1);
    }
    std::cout << ans << "\n";
}*/

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
