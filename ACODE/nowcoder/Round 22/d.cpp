#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
	int n, m;
	std::cin >> n >> m;
    std::vector<std::array<int, 3>> edges(m);
    std::vector<i64> cnt2(n), cnt5(n);
    for (int i = 0; i < n; ++i) {
    	i64 x;
    	std::cin >> x;
    	while (x % 2 == 0) cnt2[i]++, x /= 2;
    	while (x % 5 == 0) cnt5[i]++, x /= 5;
    }
    for (int i = 0; i < m; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	--x, --y;
    	edges[i] = {std::min(cnt2[x] + cnt2[y], cnt5[x] + cnt5[y]), x, y};
    }
    std::sort(edges.begin(), edges.end());
    i64 ans = 0;
    DSU uf(n);
    for (auto [x, u, v] : edges) {
    	if (!uf.same(u, v)) {
    		uf.merge(u, v);
    	} else {
    		ans += x;
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
