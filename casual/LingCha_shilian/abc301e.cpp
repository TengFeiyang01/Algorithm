#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

constexpr int dirs[] = {-1, 0, 1, 0, -1};

void solve() {

    int H, W, T;
    std::cin >> H >> W >> T;
    
    std::vector<std::string> S(H);
    for (int i = 0; i < H; i++) {
        std::cin >> S[i];
    }
    
    std::string s = "SoG";
    std::vector<std::pair<int, int>> p;
    for (auto c : s) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (S[i][j] == c) {
                    p.emplace_back(i, j);
                }
            }
        }
    }
    
    int N = p.size();

    std::vector dis(N, std::vector<int>(N));

    for (int i = 0; i < N; ++i) {
        std::queue<std::pair<int, int>> q;
        std::vector d(H, std::vector(W, -1));
        q.push(p[i]);
        d[p[i].first][p[i].second] = 0;

    
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int nx = x + dirs[k];
                int ny = y + dirs[k + 1];
                
                if (0 <= nx && nx < H && 0 <= ny && ny < W && S[nx][ny] != '#' && d[nx][ny] == -1) {
                    d[nx][ny] = d[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }

        for (int j = 0; j < N; ++j) {
            dis[i][j] = d[p[j].first][p[j].second];
        }
    }

    std::vector dp(1 << N, std::vector(N, T + 1));
    dp[1][0] = 0;

    int ans = -1;
    for (int s = 1; s < (1 << N); s += 2) {
        if (dp[s][N - 1] <= T) {
            ans = std::max(ans, __builtin_popcount(s) - 2);
        }
        for (int i = 0; i < N; ++i) {
            if (s >> i & 1) {
                for (int j = 0; j < N; ++j) {
                    if ((~s >> j & 1) and dis[i][j] != -1) {
                        dp[s | 1 << j][j] = std::min(dp[s | 1 << j][j], dp[s][i] + dis[i][j]);
                    }
                }
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
