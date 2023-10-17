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

const int N = 2e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::array<int, 2>> a(n);
    std::vector<std::array<int, 3>> q(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][0] >> a[i][1];
    }
    for (int j = 0; j < m; ++j) {
        std::cin >> q[j][0] >> q[j][1];
        q[j][2] = j;
    }

    std::sort(q.begin(), q.end(), [&](std::array<int, 3> x, std::array<int, 3> y){ 
        if (x[1] == y[1]) {
            return x[0] <= y[0];
        }
        return x[1] <= y[1];
    });
    std::sort(a.begin(), a.end(), [&](std::array<int, 2> x, std::array<int, 2> y){ 
        if (x[1] == y[1]) {
            return x[0] <= y[0];
        }
        return x[1] <= y[1];
    });

    Fenwick<int> tr(N);
    std::vector<int> ans(m);
    int j = 0;
    for (int i = 0; i < m; ++i) {
        int l = q[i][0], r = q[i][1], idx = q[i][2];
        if (l < r) {
            while (j < n and a[j][1] < r) {
                tr.add(a[j][0], 1);
                tr.add(a[j][1] + 1, -1);
                j++;
            }
            ans[idx] = tr.sum(l + 1);
        }
    }

    for (int i = 0; i < n; ++i) {
        a[i][0] = N - a[i][0];
        a[i][1] = N - a[i][1];
        std::swap(a[i][0], a[i][1]);
    }

    for (int j = 0; j < m; ++j) {
        q[j][0] = N - q[j][0];
        q[j][1] = N - q[j][1];
    }

    tr.init(N);
    std::sort(q.begin(), q.end(), [&](std::array<int, 3> x, std::array<int, 3> y){ 
        if (x[1] == y[1]) {
            return x[0] <= y[0];
        }
        return x[1] <= y[1];
    });    
    std::sort(a.begin(), a.end(), [&](std::array<int, 2> &x, std::array<int, 2> &y){ 
        if (x[1] == y[1]) {
            return x[0] <= y[0];
        }
        return x[1] <= y[1];
    });

    j = 0;
    for (int i = 0; i < m; ++i) {
        int l = q[i][0], r = q[i][1], idx = q[i][2];
        if (l < r) {
            while (j < n and a[j][1] < r) {
                tr.add(a[j][0], 1);
                tr.add(a[j][1] + 1, -1);
                j++;
            }
            ans[idx] += tr.sum(l + 1);
        }
    }

    for (int i = 0; i < m; ++i) {
        std::cout << ans[i] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}