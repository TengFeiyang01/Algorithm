#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> mark(n);
    for (int i = 0; i < k; i++) {
        int a;
        std::cin >> a;
        a--;
        mark[a] = 1;
    }
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<int> dis(n);
    auto bfs = [&](int x) {
        std::queue<int> q;
        dis.assign(n, -1);
        q.push(x);
        dis[x] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            
            for (auto y : adj[x]) {
                if (dis[y] == -1) {
                    dis[y] = dis[x] + 1;
                    q.push(y);
                }
            }
        }
        
        int t = -1;
        for (int i = 0; i < n; i++) {
            if (mark[i] && (t == -1 || dis[i] > dis[t])) {
                t = i;
            }
        }
        return t;
    };
    int a = bfs(0);
    int b = bfs(a);
    
    auto f = dis;
    bfs(b);
    for (int i = 0; i < n; i++) {
        f[i] = std::max(f[i], dis[i]);
    }
    int ans = *std::min_element(f.begin(), f.end());
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
 