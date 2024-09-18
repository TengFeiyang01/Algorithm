#include <iostream>
#include <cstring>

const int inf = 0x3f3f3f3f;
const int MAX_N = 400; // 假设最大行数
const int MAX_M = 400; // 假设最大列数

int g[MAX_N][MAX_M];
int dist[MAX_N][MAX_M];
std::pair<int, int> queue[MAX_N * MAX_M * 4]; 
int front, rear;

void solve() {
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> g[i][j];
            dist[i][j] = inf; 
        }
    }

    // 初始化队列
    front = 0;
    rear = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 0) {
                queue[rear++] = {i, j};
                dist[i][j] = 0;
            }
        }
    }

    int dirs[] = {-1, 0, 1, 0, -1};

    while (front < rear) {
        auto t = queue[front++];
        int i = t.first, j = t.second;

        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (0 <= x && x < n && 0 <= y && y < m && g[x][y] != -1) {
                if (dist[i][j] + 1 < dist[x][y]) {
                    dist[x][y] = dist[i][j] + 1;
                    queue[rear++] = {x, y};
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
