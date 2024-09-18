#include <bits/stdc++.h>


#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<PII> g[n];
    for (int i = 1; i < n; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	x--, y--;
    	if (x > y) {
    		std::swap(x, y);
    	}
        g[y].emplace_back(x, i);
    	g[x].emplace_back(y, i);
    }
    int ans = 0;
    std::function<void(int, int, int, int)> dfs = [&](int u, int fa, int t, int cnt) {
    	ans = std::max(ans, cnt);
    	for (auto&[v, cur] : g[u]) {
            if (v == fa) continue;
            dfs(v, u, cur, cnt + (cur < t));
    	}
    };

    dfs(0, -1, 0, 1);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
