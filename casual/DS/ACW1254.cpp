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
    int n, m, t;
    std::cin >> n >> m >> t;
    std::vector<int> v(n), w(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> w[i] >> v[i];
    }
    DSU uf(n);
    for (int i = 0; i < m; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	--x, --y;
    	uf.merge(x, y);
    }
    
    for (int i = 0; i < n; ++i) {
        int x = uf.find(i);
    	if (x != i) {
    		v[x] += v[i];
    		w[x] += w[i];
    		w[i] = v[i] = 0;
    	} 
    }

    std::vector<int> dp(t + 1);
    for (int i = 0; i < n; ++i) {
        if (uf.f[i] != i) continue;
    	for (int j = t; j >= w[i]; --j) {
    		dp[j] = std::max(dp[j], dp[j - w[i]] + v[i]);
    	}
    }
    std::cout << dp[t] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
