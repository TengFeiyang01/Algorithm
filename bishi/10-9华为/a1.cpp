#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f; // 无穷大
using i64 = long long;
int dist[2000][2000];

int main() {
    int m, n; // 网格的行数和列数
    std::cin >> m >> n;
    
    int sx, sy, tx, ty; // 起点和终点的坐标
    std::cin >> sx >> sy >> tx >> ty;
    
    int k; // 障碍物的数量
    std::cin >> k;
    
    // 使用 int[2000][2000] 初始化距离
    for (int i = 0; i < 2000; ++i) {
        for (int j = 0; j < 2000; ++j) {
            dist[i][j] = inf; // 初始化为无穷大
        }
    }
    
    // 坐标调整为 0-based
    sx--, sy--, tx--, ty--;
    
    dist[sx][sy] = 0; // 起点距离为 0
    
    // 读取障碍物位置
    for (int i = 0; i < k; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x, --y; // 坐标调整为 0-based
        dist[x][y] = -1; // 标记障碍物位置
    }
    
    std::queue<std::pair<int, int>> q; // 使用队列进行 BFS
    q.push({sx, sy});
    
    // 方向数组，表示四个可能的移动方向
    int dirX[] = {-1, 0, 1, 0}; // 行方向
    int dirY[] = {0, -1, 0, 1}; // 列方向
    
    while (!q.empty()) {
        auto [x, y] = q.front(); // 获取队头元素
        q.pop();
        
        // 遍历四个方向
        for (int p = 0; p < 4; ++p) {
            int i = x + dirX[p];
            int j = y + dirY[p];
            
            // 检查是否在边界内，且不是障碍物，并且更新距离
            if (0 <= i && i < m && 0 <= j && j < n && dist[i][j] != -1 && dist[i][j] > dist[x][y] + 1) {
                dist[i][j] = dist[x][y] + 1; // 更新距离
                q.push({i, j}); // 入队
            }
        }
    }
    
    // 如果目标位置仍为无穷大，表示不可达
    if (dist[tx][ty] == inf) {
        dist[tx][ty] = -1;
    }
    
    // 输出结果
    std::cout << dist[tx][ty] << std::endl;
    return 0;
}
