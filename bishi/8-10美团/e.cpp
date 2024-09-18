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
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        a[i + n] = a[i];
    }
    std::vector<std::array<int, 3>> qry(q + 1);
    int l = 0, r = 2 * n - 1;
    for (int i = 1; i <= q; ++i) {
        std::string op;
        int x;
        std::cin >> op >> x;
        if (op == "L") {
            qry[i] = std::array<int, 3>{l, l + x - 1, i};
            if (l + x > n - 1) {
                l += x - n;
            } else {
                l += x;
            }
        } else {
            qry[i] = std::array<int, 3>{r - x + 1, r, i};
            if (r - x <= n - 1) {
                r += n - x;
            } else {
                r -= x;
            }
        }
    }

    std::sort(qry.begin() + 1, qry.end(), [&](auto x, auto y){
        return x[1] < y[1];
    });

    Fenwick<int> tr(2 * n + 2);
    std::vector<int> ans(q + 1);
    std::map<int, int> pre;

    for (int i = 1, j = 0; i <= q; ++i) {
        while (j < qry[i][1]) {
            ++j;
            if (pre[a[j]]) {
                tr.add(pre[a[j]], -1);
            }
            tr.add(j, 1);
            pre[a[j]] = j;
        }
        ans[qry[i][2]] = tr.rangeSum(qry[i][0], qry[i][1] + 1);
    }
    for (int i = 1; i <= q; ++i) {
        std::cout << ans[i] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
