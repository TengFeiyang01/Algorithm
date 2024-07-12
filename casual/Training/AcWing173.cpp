#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string g[n];
    int ans[n][m];
    memset(ans, -1, sizeof ans);
    std::queue<PII> q;
    for (int i = 0; i < n; ++i) {
        std::cin >> g[i];
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) 
            if (g[i][j] == '1') {
                ans[i][j] = 0;
                q.push({i, j});
            }

    while (!q.empty()) {
        auto[x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;
            if (ans[nx][ny] != -1) continue;
            q.push({nx, ny});
            ans[nx][ny] = ans[x][y] + 1;
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) 
            std::cout << ans[i][j] << " \n"[j == m - 1];    

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
