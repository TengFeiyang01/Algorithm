#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n, std::vector<int>(m));
    std::vector<std::vector<int>> dist(n, std::vector<int>(m, inf));
    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> g[i][j];
            if (g[i][j] == 0) {
                q.push({i * m + j, 0});
                dist[i][j] = 0;
            }
        }
    }   
    int dirs[] = {-1, 0, 1, 0, -1};
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int i = t.first / m, j = t.first % m, d = t.second;
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (0 <= x and x < n and 0 <= y and y < m and g[x][y] != -1) {
                if (d + 1 < dist[x][y]) {
                    dist[x][y] = d + 1;
                    q.push({x * m + y, d + 1});
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 1 and dist[i][j] != inf) {
                ans += dist[i][j];
            }
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
