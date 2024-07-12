#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

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
    std::vector<int> h(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> h[i];
    }

    std::vector<std::array<int, 3>> edges(m);
    for (int i = 0; i < m; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	edges[i] = {std::max(h[u], h[v]), u, v};
    }

    std::sort(edges.begin(), edges.end());

    int q;
    std::cin >> q;

    std::vector<std::array<int, 4>> queries(q);
    
    for (int i = 0; i < q; ++i) {
        int a, b, e;
        std::cin >> a >> b >> e;
        --a, --b;
        queries[i] = {h[a] + e, a, b, i};
    }
    std::sort(queries.begin(), queries.end()); 
    

    DSU uf(n);
    int j = 0;
    std::vector<bool> ans(q);
    for (auto [w, u, v, i] : queries) {
        while (j < m and edges[j][0] <= w) {
            uf.merge(edges[j][1], edges[j][2]);
            j++;
        }
        ans[i] = uf.same(u, v);
    }

    for (int i = 0; i < q; ++i) {
        std::cout << (ans[i] ? "YES\n" : "NO\n");
    }
    std::cout << "\n";
}   

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
