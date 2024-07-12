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
    std::vector<int> g[n], cnt(n);
    for (int i = 0; i < n - 1; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	g[x - 1].push_back(y - 1);
    	g[y - 1].push_back(x - 1);
    }

    //对 1 号点特殊处理

    std::function<int(int, int)> dfs = [&](int u, int fa) ->int {
    	int son = 0, f = 1;
    	for (int v : g[u]) {
    		if (v != fa) {
                f = 0;
    			son += dfs(v, u);
    		}
    	}
    	return cnt[u] = son + f;
    };
    dfs(0, -1);
    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	x--, y--;
    	std::cout << 1LL * cnt[x] * cnt[y] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
