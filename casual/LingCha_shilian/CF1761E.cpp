#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector g(n, std::vector<int>(n));
    std::vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char x;
            std::cin >> x;
            g[i][j] = x - '0';
            deg[i] += g[i][j];
        }
    }
    
    std::vector<std::vector<int>> comp;
    
    std::vector<int> vis(n);
    
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        
        std::vector<int> q;
        q.push_back(i);
        vis[i] = 1;
        
        for (int i = 0; i < int(q.size()); i++) {
            int x = q[i];
            
            for (int y = 0; y < n; y++) {
                if (g[x][y] && !vis[y]) {
                    q.push_back(y);
                    vis[y] = 1;
                }
            }
        }
        
        comp.push_back(q);
    }
    
    if (comp.size() == 1) {
        std::cout << 0 << "\n";
        return;
    }
    
    for (auto s : comp) {
        if (s.size() == 1) {
            std::cout << 1 << "\n";
            std::cout << s[0] + 1 << "\n";
            return;
        }
        if (deg[s.back()] != int(s.size()) - 1) {
            std::cout << 1 << "\n";
            std::cout << s.back() + 1 << "\n";
            return;
        }
        for (auto x : s) {
            if (deg[x] != int(s.size()) - 1) {
                std::cout << 1 << "\n";
                std::cout << x + 1 << "\n";
                return;
            }
        }
    }
    
    if (comp.size() > 2) {
        std::cout << 2 << "\n";
        std::cout << comp[0][0] + 1 << " " << comp[1][0] + 1 << "\n";
        return;
    }
    
    if (comp[0].size() > comp[1].size()) {
        std::swap(comp[0], comp[1]);
    }
    
    std::cout << comp[0].size() << "\n";
    for (auto x : comp[0]) {
        std::cout << x + 1 << " \n"[x == comp[0].back()];
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