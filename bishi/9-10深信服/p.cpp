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

int dirs[] = {-1, 0, 1, 0, -1};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		std::cin >> g[i][j];

    	}
    }
    DSU uf(n * m);

    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		for (int k = 0; k < 4; ++k) {
    			int x = i + dirs[k], y = j + dirs[k + 1];
    			if (0 <= x and x < n and 0 <= y and y < m and g[i][j] != -1 and g[x][y] != -1) {
    				uf.merge(i * m + j, x * m + y);
    			}
    		}    
    	}
    }
    std::vector<int> dp(n * m);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if (g[i][j] != -1)	{
	    		dp[uf.find(i * m + j)] += g[i][j];
    			ans = std::max(ans, dp[uf.find(i * m + j)]);
    		}
    	}
    }
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if (g[i][j] == -1) {
    			std::vector<int> t;
    			for (int x : {i-1, i, i+1}) {
    				for (int y : {j - 1, j, j + 1}) {
    					if (x == i and y == j) continue;
    					if (0 <= x and x < n and 0 <= y and y < m) 
	    					t.push_back(x * m + y);
    				}
    			}
    			for (auto x : t) {
    				for (auto y : t) {
    					if (x != y and (x == 0 or y == 0)) {
    						ans = std::max(ans, dp[x] + dp[y]);
    					}
    				}
    			}
    		}
    	}
    }
    std::cout << ans <<"\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
