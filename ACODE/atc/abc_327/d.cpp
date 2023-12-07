#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    DSU uf(2 * n);
    std::vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) {
    	std::cin >> a[i];
        --a[i];
    }
    for (int j = 0; j < m; ++j) {
    	std::cin >> b[j];
        --b[j];
        if (uf.same(a[j], b[j])) {
            std::cout << "No\n";
            return;
        } else {
            uf.merge(a[j], b[j] + n);
            uf.merge(b[j], a[j] + n);
        }
    }   

    std::vector<int> s(n, -1);

    std::cout << "Yes\n";    
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
