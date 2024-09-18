#include <bits/stdc++.h>

using i64 = long long;
constexpr int inf = 0x3f3f3f3f;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }
    
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int kth(T k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};


void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::array<int, 2>> p(n);
    std::vector<int> h;
    for (auto &[x, y] : p) {
        std::cin >> y >> x;
        h.push_back(y);
    }

    std::vector<std::array<int, 4>> e;

    for (int i = 0; i < q; ++i) {
        int x1, x2, y1, y2;
        std::cin >> x1 >> x2 >> y1 >> y2;
        e.push_back({y2, x2, 1, i});
        e.push_back({y2, x1 - 1, -1, i});
        e.push_back({y1 - 1, x2, -1, i});
        e.push_back({y1 - 1, x1 - 1, 1, i});
    }
    
    std::sort(h.begin(), h.end());
    h.erase(std::unique(h.begin(), h.end()), h.end());
    int m = h.size();
    std::sort(p.begin(), p.end());
    std::sort(e.begin(), e.end());

    Fenwick<int> tr(200013);

    auto findl = [&](int x) {
        return std::lower_bound(h.begin(), h.end(), x) - h.begin();
    };
    auto findr = [&](int x) {
        return std::upper_bound(h.begin(), h.end(), x) - h.begin();
    };
    std::vector<int> ans(q);
    int k = 0;
    for (auto &[a, b, c, d] : e) {
        while (k < p.size() and p[k][0] <= a)
            tr.add(findl(p[k][1]), 1), k++;
        ans[d] += c * tr.sum(findr(b));
    }
    for (int i = 0; i < q; ++i) std::cout << ans[i] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
