#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> b(n);
    std::iota(b.begin(), b.end(), 0);
    std::vector<std::vector<int>> a(n, std::vector<int>(k));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            std::cin >> a[i][j];
        }
        std::sort(a[i].begin(), a[i].end(), std::greater<int>());
    }
    std::stable_sort(b.begin(), b.end(), [&](int i, int j) {
        return a[i] > a[j];
    });

    for (int i = 0; i < m; ++i) {
        std::cout << b[i] + 1 << " \n"[i == m - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();

    return 0;
}