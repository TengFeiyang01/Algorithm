#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct Boom {
    int x, y, t, k;
};

// 计算曼哈顿距离
int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool check(int t, int n, int m, const vector<Boom>& booms, const vector<vector<int>>& dist) {
    vector<bool> st(n, false);
    queue<int> q;

    // 找到所有能够在时间 t 引爆的炸弹
    for (int i = 0; i < n; ++i) {
        if (booms[i].t <= t) {
            st[i] = true;
            q.push(i);
        }
    }

    // 广度优先搜索（BFS），找出所有能够引爆的炸弹
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        for (int j = 0; j < n; ++j) {
            if (!st[j] && dist[x][j] <= booms[x].k) {
                st[j] = true;
                q.push(j);
            }
        }
    }

    // 统计已经引爆的炸弹数量
    int count = 0;
    for (bool s : st) {
        if (s) ++count;
    }

    return count >= m;
}

void solve() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, m;
        cin >> n >> m;
        
        vector<Boom> booms(n);
        vector<vector<int>> dist(n, vector<int>(n, 0));
        
        // 读取所有炸弹的输入数据
        for (int i = 0; i < n; ++i) {
            cin >> booms[i].x >> booms[i].y >> booms[i].t >> booms[i].k;
            // 计算炸弹之间的曼哈顿距离
            for (int j = 0; j < i; ++j) {
                dist[i][j] = dist[j][i] = manhattanDistance(booms[i].x, booms[i].y, booms[j].x, booms[j].y);
            }
        }

        int l = 0, r = 1e9;

        // 二分查找最小等待时间
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid, n, m, booms, dist)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        cout << l << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
