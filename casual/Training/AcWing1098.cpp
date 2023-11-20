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
const int N = 1e3 + 13;
int n, m;
int g[N][N]{0};
bool st[N][N]{0};
std::queue<PII> q;
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

int bfs(int sx, int sy) {
    q.push({sx, sy});
    int cur = 0;
    st[sx][sy] = true;
    
    while (!q.empty()) {
        auto[x, y] = q.front();
        q.pop();
        cur++;
        for (int i = 0; i < 4; ++i) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b] || (g[x][y] >> i & 1)) continue;
            q.push({a, b});
            st[a][b] = true;
        }
    }
    return cur;
}


void solve() {
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> g[i][j];
    int cnt = 0, area = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!st[i][j]) {
                area = std::max(area, bfs(i, j));
                cnt++;
            }
    std::cout << cnt << "\n" << area << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
