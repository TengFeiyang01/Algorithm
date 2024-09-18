#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;


std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}
		
struct Edge {
    int u, v, w;
    bool operator<(const Edge& b) const {
        return w < b.w;
    }
};


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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    sieve(2000001);
    std::vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
    	for (int j = i + 1; j < n; ++j) {
    		if (minp[a[i] + a[j]] == a[i] + a[j]) {
    			edges.push_back({i, j, a[i] + a[j]});
    		}
    	}
    }
    std::sort(edges.begin(), edges.end());
    DSU uf(n);
    for (int i = 0; i < edges.size(); ++i) {
    	int u = edges[i].u, v = edges[i].v, w = edges[i].w;
    	uf.merge(u, v);
    }
    DSU uf1(n);
    std::vector<int> res(n, 0);
    for (int i = 0; i < edges.size(); ++i) {
    	int u = edges[i].u, v = edges[i].v, w = edges[i].w;
    	if (uf1.merge(u, v)) {
    		res[uf.find(u)] += w;
    	}
    }
    int ans = inf;

    for (int i = 0; i < n; ++i) {
    	if (uf.size(i) == 1) continue;
    	ans = std::min(ans, res[uf.find(i)]);
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
