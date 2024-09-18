#include <bits/stdc++.h>
using i64 = long long;
constexpr int inf = 0x3f3f3f3f;

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
        if (x < y) {
            std::swap(x, y);
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

// 线段覆盖，即从代价小的操作开始
// 给li≤j≤ri中的每个点合并成一个联通块，每合并一次的代价是 ci。最后看是否是同个连通块即可。
// 连通块就用并查集维护，合并时总是以编号大的点为根

void solve() { 
    int n, q;
    std::cin >> n >> q;
    std::vector<std::array<int, 3>> seg(q);
    for (auto &[l, r, c] : seg) {
        std::cin >> l >> r >> c;
        --l, --r;
    }
    std::ranges::sort(seg, {}, [&](auto x){return x[2];});
    DSU uf(n);

    // 合并的时候合并到大的编号
    auto merge = [&](int l, int r) {
        int cnt = 1;
        int cur = uf.find(l);
        while (cur < r) {
            int nxt = uf.find(cur + 1);
            uf.merge(cur, nxt);
            cur = nxt;
            ++cnt;
        }
        return cnt;
    };
    i64 ans = 0;
    for (auto &[l, r, c] : seg) {
        int cnt = merge(l, r);
        ans += 1ll * cnt * c;
    }

    if (uf.size(0) != n) {
        ans = -1;
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(0),std::cin.tie(0);
    
    solve();

    return 0;
}