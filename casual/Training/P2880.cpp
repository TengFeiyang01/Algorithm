#include <bits/stdc++.h>
 
void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> Log(n + 1, -1);
    std::vector f(n, std::vector<int>(22));
    for (int i = 0; i < n; ++i) {
        std::cin >> f[i][0];
    }
    auto g = f;

    //init
    for (int i = 1, k = 1; i <= n; ++i) {
        if (i == (1 << k)) k++;
        Log[i] = k - 1;
    }
    
    for (int k = 1; k <= Log[n]; ++k) {
        for (int i = 0; i + (1 << k) - 1 < n; ++i) {
            f[i][k] = std::max(f[i][k - 1], f[i + (1 << k - 1)][k - 1]);
            g[i][k] = std::min(g[i][k - 1], g[i + (1 << k - 1)][k - 1]);
        }
    }
    
    for (int i = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r;
        int k = Log[r - l + 1];
        l--, r--;
        int x = std::max(f[l][k], f[r - (1 << k) + 1][k]);
        int y = std::min(g[l][k], g[r - (1 << k) + 1][k]);
        std::cout << x - y << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
