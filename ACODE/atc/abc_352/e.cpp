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
    std::vector<std::array<int, 3>> edges;
    for (int i = 0; i < m; ++i) {
    	int k, c;
    	std::cin >> k >> c;
    	int pre = -1;
    	for (int j = 0; j < k; ++j) {
    		int x;
    		std::cin >> x;
    		--x;
    		if (j) {
    			edges.push_back({c, x, pre});
    		}
    		pre = x;
    	}
    }
    std::ranges::sort(edges);
    int tot = 0;
    i64 ans = 0;
    DSU uf(n);

    for (auto &[w, u, v] : edges) {
    	if (uf.merge(u, v)) {
    		tot++;
    		ans += w;
    	} 
    }
    if (tot == n - 1) {
    	std::cout << ans << "\n";
    } else {
    	std::cout << -1 << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
