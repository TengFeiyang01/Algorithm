#include <bits/stdc++.h>

using i64 = long long;

int dirs[] = {0, 1, 0, -1, 0};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n + 1);
    std::vector<std::vector<int>> st(n + 1, std::vector<int>(m + 1, -1));
    int startX, startY, endX, endY;

    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        a[i] = " " + a[i]; 
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'M') {
                startX = i;
                startY = j;
            } else if (a[i][j] == '*') {
                endX = i;
                endY = j;
            }
        }
    }

    int l;
    std::cin >> l;

    std::queue<std::pair<int, int>> q;
    q.emplace(startX, startY);
    st[startX][startY] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == endX && y == endY) {
            break;
        }

        int branch_count = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i], ny = y + dirs[i + 1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != 'X' && st[nx][ny] == -1) {
                ++branch_count;
            }
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i], ny = y + dirs[i + 1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != 'X' && st[nx][ny] == -1) {
                st[nx][ny] = st[x][y] + (branch_count > 1 ? 1 : 0);
                q.emplace(nx, ny);
            }
        }
    }

    if (st[endX][endY] == l) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
