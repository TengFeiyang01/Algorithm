#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

using namespace std;

const int inf = INT_MAX;

int main() {
    int w, m, n;
    cin >> w >> m >> n;

    vector<vector<vector<int>>> fa(m, vector<vector<int>>(n, vector<int>(2, -1)));
    vector<vector<int>> g(m, vector<int>(n));
    int sx = 0, sy = 0, ex = 0, ey = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            string v;
            cin >> v;
            if (v == "s") {
                sx = i;
                sy = j;
                g[i][j] = 0;
            } else if (v == "t") {
                ex = i;
                ey = j;
                g[i][j] = inf;
            } else {
                g[i][j] = stoi(v);
            }
        }
    }

    vector<vector<int>> dis(m, vector<int>(n, -1));
    deque<pair<int, int>> q;
    q.push_back({sx, sy});
    dis[sx][sy] = 0;

    while (!q.empty()) {
        auto current = q.front();
        q.pop_front();
        int x = current.first, y = current.second;
        int d = dis[x][y];

        int directions[4][2] = {{x, y + 1}, {x, y - 1}, {x + 1, y}, {x - 1, y}};
        for (auto& dir : directions) {
            int a = dir[0], b = dir[1];
            if (a >= 0 && a < m && b >= 0 && b < n && dis[a][b] == -1 && w + d + 1 < g[a][b]) {
                fa[a][b][0] = x;
                fa[a][b][1] = y;
                q.push_back({a, b});
                dis[a][b] = d + 1;
            }
        }
    }

    if (dis[ex][ey] == -1) {
        cout << "s\n";
        return 0;
    }

    vector<int> ans;
    int x = fa[ex][ey][0], y = fa[ex][ey][1];
    while (x != -1) {
        ans.push_back(g[x][y]);
        int tempX = fa[x][y][0];
        int tempY = fa[x][y][1];
        x = tempX;
        y = tempY;
    }

    if (!ans.empty()) {
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());
    cout << "s ";
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if (i < ans.size() - 1) {
            cout << " ";
        }
    }
    cout << " t\n";

    return 0;
}
