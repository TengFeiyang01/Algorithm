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
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	edges.push_back({u, v});
    }
    std::vector<int> ans;
    int mx = -1;
    auto get = [&](int q) {
    	std::vector<int> d(n), res;
    	DSU uf(n);

    	for (int i = 0; i < m; ++i) {
    		auto [u, v] = edges[i];
    		if (!(u == q or v == q)) {
    			continue;
    		}
    		if (uf.same(u, v)) continue;
    		d[u]++;
    		d[v]++;
    		uf.merge(u, v);
    		res.push_back(i + 1);
    	}
    	for (int i = 0; i < m; ++i) {
    		auto [u, v] = edges[i];
    		if (uf.same(u, v)) continue;
    		d[u]++;
    		d[v]++;
    		uf.merge(u, v);
    		res.push_back(i + 1);
    	}

    	if (abs(d[0] - d[1]) > mx) {
    		mx = abs(d[0] - d[1]);
    		ans = res;
    	}
    };

    get(0);
    get(n - 1);
    for (auto x : ans) {
    	std::cout << x << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
