#include <bits/stdc++.h>

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
    
    //[l, r] -> t.rangeSum(l, r + 1)
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

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    auto va = a;
    std::sort(va.begin(), va.end());
    for (auto &x : a) {
        x = std::lower_bound(va.begin(), va.end(), x) - va.begin();
    }
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " \n"[i == n - 1]
    }

    i64 ans = 0;

    for (int i = 1; i <= n; ++i) {
        ans += 1LL * (i - 1) * (n - i + 1);
    }
    std::vector<std::vector<std::pair<int, int>>> R(n);
    std::vector<int> stk{n};
    Fenwick<int> f1(n), f2(n);
    for (int i = n - 1; i >= 0; --i) {
        while (stk.size() > 1 and a[i] < a[stk.back()]) {
            int x = stk.back();
            stk.pop_back();
            R[i].emplace_back(a[x], stk.back() - x);
            f2.add(a[x], x - stk.back());
        }
        R[i].emplace_back(a[i], i - stk.back());
        f2.add(a[i], stk.back() - i);
        stk.push_back(i);
    }
    stk = {-1};
    i64 res = 0;
    for (int i = 0; i < n; ++i) {
        while (stk.size() > 1 and a[i] > a[stk.back()]) {
            int x = stk.back();
            stk.pop_back();
            res += 1LL * f2.rangeSum(a[x], n) * (stk.back() - x);
            f1.add(a[x], stk.back() - x);
        }
        res += 1LL * f2.rangeSum(a[i], n) * (i - stk.back());
        f1.add(a[i], i - stk.back());
        stk.push_back(i);

        for (auto [v, x] : R[i]) {
            res += 1LL * f1.sum(v + 1) * x;
            f2.add(v, x);
        }
        ans -= res;
    }

    std::cout << ans << "\n";
}


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
