#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cmath>
 
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector dp(n, std::vector<int>(n, -1));
    std::queue<std::tuple<int, int, int>> q;
    q.emplace(0, 0, n - 1);
    
    while (!q.empty()) {
        auto [d, x, y] = q.front();
        q.pop();
        
        if (dp[x][y] != -1) {
            continue;
        }
        dp[x][y] = d;
        for (auto a : adj[x]) {
            for (auto b : adj[y]) {
                if (c[a] != c[b]) {
                    q.emplace(d + 1, a, b);
                }
            }
        }
    }
    
    std::cout << dp[n - 1][0] << "\n";
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
