#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<std::array<int, 2>> adj(n);
    for (int i = 0; i < n; ++i) {
    	int l, r;
    	std::cin >> l >> r;
    	adj[i] = {-1, -1};
    	if (l) adj[i][0] = l - 1;;
    	if (r) adj[i][1] = r - 1;
    }

    int ans = inf;
    std::function<void(int, int)> dfs = [&](int u, int cnt) {
    	if (adj[u] == std::array<int, 2>{-1, -1}) {
    		ans = std::min(ans, cnt);
            return;
    	}
        if (adj[u][0] != -1) {
            dfs(adj[u][0], cnt + (s[u] != 'L'));
        }
        if (adj[u][1] != -1) {
            dfs(adj[u][1], cnt + (s[u] != 'R'));
        }
    };
    dfs(0, 0);
    std::cout << ans << "\n";
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
