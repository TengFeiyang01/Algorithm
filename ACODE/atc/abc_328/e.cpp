#include <bits/stdc++.h>

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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    i64 K;
    std::cin >> N >> M >> K;
    
    std::vector<int> u(M), v(M);
    std::vector<i64> w(M);
    for (int i = 0; i < M; i++) {
        std::cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;
    }
    
    i64 ans = K;
    auto dfs = [&](auto self, int i, i64 s, DSU dsu) {
        if (i == M) {
            bool ok = true;
            for (int i = 0; i < N; i++) {
                if (!dsu.same(0, i)) {
                    ok = false;
                }
            }
            if (ok) {
                ans = std::min(ans, s %K);
            }
            return;
        }
        self(self, i + 1, s, dsu);
        if (!dsu.same(u[i], v[i])) {
            dsu.merge(u[i], v[i]);
            self(self, i + 1, s + w[i], dsu);
        }
    };
    dfs(dfs, 0, 0, DSU(N));
    std::cout << ans << "\n";
    
    return 0;
}