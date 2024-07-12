#include <bits/stdc++.h>

using i64 = long long;
constexpr int mod = 1e9 + 7;


i64 qpow(i64 x, int y) {
    i64 res = 1;
    for (; y; y /= 2, x *= x, x %= mod)
        if (y & 1)
            res *= x, res %= mod;
    return res;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> g[n];
    //f[x]从x号出发期望经过多少条能到达n f[n] = 0

    std::vector<i64> f(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        g[x - 1].emplace_back(y - 1);
    }

    for (int i = n - 2; i >= 0; --i) {
        int l = g[i].size();
        f[i] = 1;
        for (int j : g[i]) {
            f[i] += f[j] * qpow(l, mod - 2);
            f[i] %= mod;
        }
    }

    std::cout << f[0] << "\n";
}


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
