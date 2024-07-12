#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    int res = n + m - 2;
    if (k < res or (k - res) % 2) {
        std::cout << "NO\n";
    } else {
        // 起点处 绕 - | - | 
        // 终点转圈即可
        std::cout << "YES\n";
        std::vector<std::string> row(n, std::string(m - 1, 'R'));
        std::vector<std::string> col(m, std::string(n - 1, 'R'));
        if ((k - res) % 4 == 2) {
            row[1][0] = 'B';
        } 
        for (int i = 1; i < m - 1; i += 2) {
            row[0][i] = 'B';
        }
        char c = 'B', d = 'R';
        if (row[0].back() == 'B') c = 'R', d = 'B';
        for (int i = 0; i < n - 1; i += 2) {
            col[m - 1][i] = c;
            if (i + 1 < n - 1) {
                col[m - 1][i + 1] = d;
            }
        }

        if (col.back().back() == 'R') {
            row[n - 1][m - 2] = row[n - 2][m - 2] = 'B';
        } else {
            col[m - 2][n - 2] = 'B';
        }
        for (int i = 0; i < n; ++i) {
            for (auto c : row[i]) {
                std::cout << c << " ";
            }
            std::cout << "\n";
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << col[j][i] << " "; 
            }
            std::cout << "\n";
        }
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
