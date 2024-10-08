#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    int ans = 0;
    
    auto work = [&]() {
        std::vector sc(n, std::vector<int>(m)), sd(n, std::vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i) {
                    sc[i][j] = sc[i - 1][j];
                }
                if (i && j < m - 1) {
                    sd[i][j] = sd[i - 1][j + 1];
                }
                sc[i][j] += (s[i][j] == '#');
                sd[i][j] += (s[i][j] == '#');
            }
        }
        std::vector score(n, std::vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j) {
                    score[i][j] = score[i][j - 1];
                    if (i + j > k) {
                        int x = i, y = j - (k + 1);
                        if (y < 0) {
                            x += y;
                            y = 0;
                        }
                        score[i][j] -= sd[x][y];
                    }
                    if (i >= k + 1) {
                        score[i][j] += sd[i - (k + 1)][j];
                    }
                }
                score[i][j] += sc[i][j];
                if (i >= k + 1) {
                    score[i][j] -= sc[i - (k + 1)][j];
                }
                ans = std::max(ans, score[i][j]);
            }
        }
    };
    
    work();
    std::reverse(s.begin(), s.end());
    work();
    for (auto &row : s) {
        std::reverse(row.begin(), row.end());
    }
    work();
    std::reverse(s.begin(), s.end());
    work();
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}