#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, s;
    std::cin >> n >> m >> s;
    --s;
    int idx = 0;
    std::vector<std::vector<std::array<int, 2>>> adj(n);
    
    for (int i = 0; i < m; ++i) {
    	int t, x, y;
    	std::cin >> t >> x >> y;
    	--x, --y;
        if (t == 1) {
            adj[x].push_back({y, 0});
        } else {
            adj[x].push_back({y, ++idx});
            adj[y].push_back({x, -idx});
        }
    }

    int ans = 0;
    
    std::vector<bool> st(n, false), d(idx + 1, false);
    
    std::function<void(int)> dfs_max = [&](int u) ->void {
        st[u] = true;
        ans++;
        for (auto [v, id] : adj[u]) {
            if (st[v]) continue;
            if (id == 0) {
                dfs_max(v);
            } else {
                d[abs(id)] = id > 0;
                dfs_max(v);
            }
        }        
    };

    std::function<void(int)> dfs_min= [&](int u) ->void {
        st[u] = true;
        ans++;
        for (auto [v, id] : adj[u]) {
            if (st[v]) continue;
            if (id == 0) {
                dfs_min(v);
            } else {
                d[abs(id)] = id < 0;
            }
        }        
    };

    dfs_max(s);
    std::cout << ans << "\n";
    for (int i = 1; i <= idx; ++i) {
        if (d[i]) {
            std::cout << "+";
        } else {
            std::cout << "-";
        }
    }

    d.assign(idx + 1, 0);
    st.assign(n, 0);
    ans = 0;
    dfs_min(s);

    std::cout << "\n" << ans << "\n";
    for (int i = 1; i <= idx; ++i) {
        if (d[i]) {
            std::cout << "+";
        } else {
            std::cout << "-";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
