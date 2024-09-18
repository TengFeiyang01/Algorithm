#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 n, l, r, ans = 0;
    std::cin >> n >> l >> r;
    std::string s;
    std::cin >> s;
    for (auto &c : s) c -= '0';
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    std::function<void(int, int, i64, int)> dfs = [&](int u, int fa, i64 cur, int d) {
        if (l <= cur and cur <= r and d) {
            ans += 1;
        }
        if (cur > r) return;
        for (auto v : adj[u]) {
            if (v != fa)    
                dfs(v, u, cur * 2LL + s[v], d + 1);
        }
    };
    for (int i = 0; i < n; ++i) dfs(i, -1, s[i], 0);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
