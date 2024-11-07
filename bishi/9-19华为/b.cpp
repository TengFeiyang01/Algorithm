#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int dirs[] = {-1, 0, 1, 0, -1};

bool check(const vector<vector<int>>& g, int n, int k, int mx) {
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;

    int dist = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            auto [x, y] = q.front(); q.pop();
            if (x == n - 1 && y == n - 1) return dist <= k;
            for (int d = 0; d < 4; ++d) {
                int i = x + dirs[d], j = y + dirs[d + 1];
                if (i >= 0 && i < n && j >= 0 && j < n && !visited[i][j] && g[i][j] <= mx) {
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        ++dist;
    }
    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> g[i][j];

    int l = 0, r = 100000000;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(g, n, k, mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}

int main() {
    solve();
    return 0;
}
