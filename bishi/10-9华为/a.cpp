#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

int dir[] = {-1, 0, 1, 0, -1};

void solve() {
    int m, n;
    std::cin >> m >> n;
    int sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;
    int k;
    std::cin >> k;
    std::vector<std::vector<int>> dist(m + 1, std::vector<int>(n + 1, inf));


    dist[sx][sy] = 0;
    for (int i = 0; i < k; ++i) {
            int x, y;
            std::cin >> x >> y;

            dist[x][y] = -1;
    }
    std::queue<int> q;
    q.push(sx * n + sy);
    
    while (!q.empty()) {
            int u = q.front();
            q.pop();
            int x = u / n, y = u % n;
            
            for (int p = 0; p < 4; ++p) {
                    int i = x + dir[p], j = y + dir[p + 1];
                    
                    if (0 <= i and i < m and j >= 0 and j < n and dist[i][j] != -1 and dist[i][j] > dist[x][y] + 1) {
                            dist[i][j] = dist[x][y] + 1;
                            q.push(i * n + j);
                    }
            }
    }
    if (dist[tx][ty] == inf) dist[tx][ty] = -1;
    std::cout << dist[tx][ty];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
