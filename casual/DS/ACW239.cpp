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
    DSU uf(n * 2);
    int ok = 1;
    std::set<int> st;
    std::vector<std::vector<std::pair<int, int>>> event(2);
    while (n--) {
    	int x, y, op;
    	std::cin >> x >> y >> op;
    	--x, --y;
        st.insert(x);
        st.insert(y);
        event[!op].push_back({x, y});
    }

    std::vector<int> b{st.begin(), st.end()};
    auto get = [&](int x) {
        return std::lower_bound(b.begin(), b.end(), x) - b.begin();
    };
    for (auto [x, y] : event[0]) {
        uf.merge(get(x), get(y));
    }
    for (auto [x, y] : event[1]) {
        if (uf.same(get(x), get(y))) {
            ok = 0;
        }
    }
    std::cout << (ok ? "YES\n" : "NO\n");
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
