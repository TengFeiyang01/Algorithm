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
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    DSU uf(n);
    for (int i = 0; i < n; ++i) {
    	for (int j = i + 1; j < n; ++j) {
            i64 tmp = a[i] * a[j];
            if (tmp > 0) {
                tmp = std::sqrt(tmp);
                if (tmp * tmp == a[i] * a[j]) {
                    uf.merge(i, j);
                }      
            }
          
    	}
    }

    std::vector<i64> ans(n + 1);
    for (int l = 0; l < n; ++l) {
    	int cnt = 0;
        std::vector<int> st(n);
    	for (int r = l; r < n; ++r) {
            if (!a[r]) {
                // 0 单独一个集合 或者和已有集合合并
                ans[std::max(cnt, 1)]++;
                continue;
            }
            if (!st[uf.find(r)]) {
                st[uf.find(r)] = 1;
                cnt++;
            }
            ans[cnt]++;
    	}
    }
    for (int i = 1; i <= n; ++i) {
    	std::cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
