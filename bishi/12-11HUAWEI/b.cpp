#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int m, n;
    std::cin >> m >> n;
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0] >> a[i][1];
    }
    std::sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
        if (x[1] != y[1]) {
            return x[1] < y[1];
        }
        return x[0] > y[0];
    });
    i64 ans = 0;
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> pq;
    for (int i = 0; i < m; ++i) {
        pq.push(0);
    }
    for (int i = 0; i < n; ++i) {
        i64 t = a[i][0], p = a[i][1];
        i64 u = pq.top();
        pq.pop();
        pq.push(u + t);
        ans = std::max(ans, u + t);
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}