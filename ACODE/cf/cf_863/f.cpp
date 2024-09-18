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
    
    int leader(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
    
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[leader(x)];
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	u--, v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    int k = std::sqrt(n);
    
    if (k * k != n or m != (k + 1) * k) {
    	std::cout << "NO\n";
    	return;
    }
    
    int x = -1;
    for (int i = 0; i < n; ++i) {
    	if (adj[i].size() != 2 and adj[i].size() != 4) {
    		std::cout << "NO\n";
    		return;
    	}
    	if (adj[i].size() == 4) {
    		x = i;
    	}
    }

    std::vector<int> e4(n), e2(n);
    DSU d4(n), d2(n);
    int m4 = 0;
    for (int u = 0; u < n; ++u) {
    	for (int v : adj[u]) {
    		if (v < u) {
    			continue;
    		}
    		if (adj[u].size() == 4 and adj[v].size() == 4) {
    			e4[u] += 1;
    			e4[v] += 1;
    			m4 += 1;
                d4.merge(u, v);
    		} else {
    			e2[u] += 1;
    			e2[v] += 1;
    			d2.merge(u, v);
    		}
    	}
    }

    if (m4 != k or d4.size(x) != k) {
    	std::cout << "NO\n";
    	return;
    }

    for (int i = 0; i < n; ++i) {
    	if (e2[i] != 2) {
    		std::cout << "NO\n";
    		return;
    	}
    }
    for (int i = 0; i < n; ++i) {
    	if (d2.size(i) != k) {
    		std::cout << "NO\n";
    		return;
    	}
    }
    std::set<int> s;
    for (int i = 0; i < n; ++i) {
    	if (adj[i].size() == 4) {
    		s.insert(d2.leader(i));
    	}
    }
    if (s.size() != k) {
    	std::cout << "NO\n";
    	return;
    }
    std::cout << "YES\n";
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
