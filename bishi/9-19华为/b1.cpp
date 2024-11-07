#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定义四个方向的移动（上、右、下、左）
const int dirs[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

// 检查是否存在满足条件的路径
bool check(const vector<int>& g, int n, int k, int mx) {
    queue<int> q;
    q.push(0); 

    vector<bool> visited(n * n, false);
    visited[0] = true;

    int dist = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            int idx = q.front(); q.pop();
            if (idx == n * n - 1) { // 到达目标位置
                return dist <= k;
            }
            int x = idx / n;
            int y = idx % n;
            for (int d = 0; d < 4; ++d) {
                int nx = x + dirs[d][0];
                int ny = y + dirs[d][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int new_idx = nx * n + ny;
                    if (!visited[new_idx] && g[new_idx] <= mx) {
                        visited[new_idx] = true;
                        q.push(new_idx);
                    }
                }
            }
        }
        ++dist;
        if (dist > k) { // 已经超出最大步数限制
            break;
        }
    }
    return false;
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> g(n * n);
    for (int i = 0; i < n * n; ++i) {
        cin >> g[i];
    }

    int l = 0, r = INT32_MAX;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(g, n, k, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << "\n";
}

int main() {
    solve();
    return 0;
}
