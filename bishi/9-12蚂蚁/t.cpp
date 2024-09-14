#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

i64 g[1001][1001];

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<i64, 2>> a(n);
    for (auto &[x, y] : a) {
        std::cin >> x >> y;
    }
    auto get = [&](int i, int j) {
        i64 d = (a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) + (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]);
        i64 r = sqrtl(d);
        return r * r == d ? (r + 1) / 2 : r / 2 + 1;
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            g[i][j] = get(i, j);
        }
    }

    int ans = 0;
    std::vector<int> vis(n);
    std::vector<i64> dist(n, inf);
    for (int i = 1; i < n; ++i) {
        dist[i] = std::min(dist[i], g[0][i]);
    }
    for (int i = 0; i < n; ++i) {
        int t = -1;
        i64 mn = inf;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && mn > dist[j]) {
                mn = dist[j];
                t = j;
            }
        }
        vis[t] = 1;
    }   
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
