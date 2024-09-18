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
    DSU uf(m * n);

    auto idx = [&](int i, int j) {
    	return i * m + j;
    };
    std::vector<std::vector<int>> a(n, std::vector(m, 0));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		std::cin >> a[i][j];
    		if (i and a[i - 1][j] != -1 and a[i][j] != -1) {
    			uf.merge(idx(i, j), idx(i - 1, j));
    		}
    		if (j and a[i][j - 1] != -1 and a[i][j] != -1) {
    			uf.merge(idx(i, j), idx(i, j - 1));
    		}
    	}
    }

    std::vector<int> f(n * m);
    int base = uf.find(0);

    std::vector<int> pos;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		f[uf.find(idx(i, j))] += a[i][j];
    		if (uf.find(idx(i, j)) == base) {
    			pos.push_back(idx(i, j));
    		}
    	}
    }
    int mx = 0;
    for (auto p : pos) {
    	int x = p / m, y = p % m;
    	for (int k = 0; k < 4; ++k) {
    		int i = x + dirs[k], j = y + dirs[k + 1];
    		if (i < 0 or i >= n or j < 0 or j >= m or a[i][j] != -1) continue;
    		for (int z = 0; z < k; ++z) {
    			int nx = i + dirs[z], ny = j + dirs[z + 1];
    			if (0 <= nx and nx < n and 0 <= ny and ny < m and a[nx][ny] != -1 and uf.find(idx(nx, ny)) != base) {
    				mx = std::max(mx, f[uf.find(idx(nx, ny))]);
    			}
    		}
    	}
    }
    std::cout << f[base] + mx << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
