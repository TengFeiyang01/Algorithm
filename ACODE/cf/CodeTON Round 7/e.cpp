#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

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
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), res(n + 1), id(n + 1), dis(n + 1);
    std::vector<std::array<int, 2>> e;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        if (i <= a[i]) {
            e.push_back({i, a[i]});
            e.push_back({i + n, a[i] + n});
        } else {
            e.push_back({i, a[i] + n});
        }
    }
    std::ranges::sort(e);

    // 每个数 [a[i], i] 看成一个区间 
    // 答案为 区间长度 - 1 - 被它完全包含的区间数量  二维数点
    Fenwick<int> tr(2 * n + 1);
    for (auto [l, r] : std::views::reverse(e)) {
        if (l <= n) {
            res[a[l]] = r - l - tr.sum(r + 1) + tr.sum(l);
        }
        tr.add(r, 1);
    }

    for (int i = 1; i <= n; ++i) {
    	std::cout << res[i] << " \n"[i == n];
    }
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
