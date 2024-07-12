#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> col(m, n);  // 记录当前这一列最高的是谁
    std::vector<std::string> s(m, std::string(n, '*'));
    for (int i = 0; i < k; ++i) {
        int x, y;
        std::cin >> x >> y;
        x = n - x + 1;
        --y;
        if (col[y] >= x) {
            col[y]--;
        }       
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n - col[i]; ++j) {
            s[i][j] = '.';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << s[j][i];
        }
        std::cout << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
