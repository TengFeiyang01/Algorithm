#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using ui64 = unsigned long long;
constexpr ui64 base1 = 9982431;
constexpr ui64 base2 = 13131;

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
};

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    s = " " + s;
    std::vector<ui64> p(n + 1), h(n + 1);
    p[0] = 1;
    h[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] * base1;
        h[i] = h[i - 1] * base2;
    }

    Fenwick<ui64> tr1(n + 1), tr2(n + 1);
    for (int i = 1; i <= n; ++i) {
        tr1.add(i, (s[i] - 'a') * p[i]);
        tr2.add(i, (s[i] - 'a') * h[i]);
    }

    while (q--) {
        int op, x, l1, r2, l2, r1;
        char c;
        std::cin >> op;
        if (op == 1) {
            std::cin >> x >> c;
            tr1.add(x, (c - s[x]) * p[x]);
            tr2.add(x, (c - s[x]) * h[x]);
            s[x] = c;
        } else {
            std::cin >> l1 >> r1 >> l2 >> r2;
            ui64 s1 = tr1.rangeSum(l1, r1 + 1);
            ui64 s2 = tr1.rangeSum(l2, r2 + 1);
            ui64 t1 = tr2.rangeSum(l1, r1 + 1);
            ui64 t2 = tr2.rangeSum(l2, r2 + 1);
            ui64 dif1 = p[abs(l1 - l2)];
            ui64 dif2 = h[abs(l1 - l2)];
            bool ok = false;
            if (l1 < l2) {
                s1 *= dif1;
                t1 *= dif2;
            } else {
                s2 *= dif1;
                t2 *= dif2;
            }
            std::cout << (s1 == s2 and t1 == t2 ? "Yes\n" : "No\n");
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
