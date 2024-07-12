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
constexpr char cs[] = "\\/\\/";
constexpr int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
constexpr int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string g[n];
    for (int i = 0; i < n; ++i) std::cin >> g[i];
    if (m + n & 1) {
        std::cout << "NO SOLUTION\n";
    } else {
        std::deque<PII> q;
        int dist[n + 1][m + 1];
        int st[n + 1][m + 1];
        memset(dist, inf, sizeof(dist));
        memset(st, 0, sizeof(dist));
        dist[0][0] = 0;
        q.push_back({0, 0});

        while (!q.empty()) {
            auto[cx, cy] = q.front(); q.pop_front();

            if (st[cx][cy]) continue;
            st[cx][cy] = 1;

            for (int i = 0; i < 4; ++i) {
                int x = cx + dx[i], y = cy + dy[i];
                if (x < 0 || y < 0 || x > n || y > m) continue;

                int a = cx + ix[i], b = cy + iy[i], w = (g[a][b] != cs[i]);
                int d = dist[cx][cy] + w;

                if (d < dist[x][y]) {
                    dist[x][y] = d;
                    if (w) q.push_back({x, y});
                    else q.push_front({x, y});
                }
            }
        }
        
        if (dist[n][m] == inf) {
            std::cout << "NO SOLUTION\n";
        } else {
            std::cout << dist[n][m] << "\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
