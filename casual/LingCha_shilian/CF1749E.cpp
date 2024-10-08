#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    int ans = -1;
    
    std::vector good(n, std::vector<int>(m, 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                if (i) good[i - 1][j] = 0;
                if (j) good[i][j - 1] = 0;
                if (i < n - 1) good[i + 1][j] = 0;
                if (j < m - 1) good[i][j + 1] = 0;
            }
        }
    }
    
    std::vector dp(n, std::vector<int>(m, -1));
    std::vector last(n, std::vector<std::pair<int, int>>(m));
    
    std::deque<std::tuple<int, int, int, int, int>> q;
    for (int i = 0; i < n; i++) {
        if (good[i][0]) {
            if (s[i][0] == '.') q.emplace_back(i, 0, 1, -1, -1);
            else q.emplace_front(i, 0, 0, -1, -1);
        }
    }
    
    while (!q.empty()) {
        auto [x, y, d, lx, ly] = q.front();
        q.pop_front();
        
        if (dp[x][y] != -1) continue;
        
        dp[x][y] = d;
        last[x][y] = {lx, ly};
        
        for (auto dx : {-1, 1}) for (auto dy : {-1, 1}) {
            int nx = x + dx, ny = y + dy;
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || !good[nx][ny]) continue;
            
            if (s[nx][ny] == '.') q.emplace_back(nx, ny, d + 1, x, y);
            else q.emplace_front(nx, ny, d, x, y);
        }
    }
    
    int x = -1;
    for (int i = 0; i < n; i++) {
        if (dp[i][m - 1] != -1 && (ans == -1 || ans > dp[i][m - 1])) {
            ans = dp[i][m - 1];
            x = i;
        }
    }
    
    if (ans == -1) {
        std::cout << "NO\n";
        return;
    }
    
    std::cout << "YES\n";
    
    int y = m - 1;
    while (1) {
        s[x][y] = '#';
        
        if (!y) break;
        
        std::tie(x, y) = last[x][y];
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << s[i] << "\n";
    }
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
