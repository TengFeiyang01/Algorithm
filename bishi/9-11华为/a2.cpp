#include <iostream>
#include <queue>
#include <cstring>

const int inf = 0x3f3f3f3f;
const int MAX_N = 400; 
const int MAX_M = 400; 

int g[MAX_N][MAX_M];
int dist[MAX_N][MAX_M];

void solve() {
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> g[i][j];
            dist[i][j] = inf; 
        }
    }

    std::queue<std::pair<int, int>> q;

    // 将所有的 0 节点放入队列，并初始化它们的距离为 0
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 0) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    int dirs[] = {-1, 0, 1, 0, -1};

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int i = t.first, j = t.second;

        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (0 <= x && x < n && 0 <= y && y < m && g[x][y] != -1) {
                if (dist[i][j] + 1 < dist[x][y]) {
                    dist[x][y] = dist[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 1 && dist[i][j] != inf) {
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
