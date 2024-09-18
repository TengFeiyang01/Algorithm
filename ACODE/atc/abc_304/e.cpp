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
    int N, M;
    std::cin >> N >> M;

    DSU dsu(N);

    for (int i = 0; i < M; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	dsu.merge(u, v);
    }

    int K;
    std::cin >> K;

    std::vector<std::pair<int, int>> bad;

    //将所有导致联通的块存起来 
    for (int i = 0; i < K; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	--x, --y;
    	x = dsu.find(x);
    	y = dsu.find(y);
    	if (x > y) std::swap(x, y);
    	bad.emplace_back(x, y);
    }

    std::sort(bad.begin(), bad.end());

    int Q;
    std::cin >> Q;

    while (Q--) {
    	int p, q;
    	std::cin >> p >> q;
    	--p, --q;

    	int x = dsu.find(p);
    	int y = dsu.find(q);
    	if (x > y) std::swap(x, y);

    	if (std::binary_search(bad.begin(), bad.end(), std::make_pair(x, y))) {
    		std::cout << "No\n";
    	} else {
    		std::cout << "Yes\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
