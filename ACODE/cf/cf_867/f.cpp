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
    int n, x, y, c, k;
    std::cin >> n >> k >> c;
    std::vector<int> g[n];
    std::vector<int> d1(n), d2(n), dep(n), son(n, -1), up(n);
    for (int i = 1; i < n; ++i) {
    	std::cin >> x >> y;
    	x--, y--;
    	g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    std::function<void(int, int, int)> dfs1 = [&](int u, int fa, int d) {
    	dep[u] = d;
    	d1[u] = d2[u] = 0;
    	for (auto& v : g[u]) {
    		if (v == fa) continue;
    		dfs1(v, u, d + 1);
    		int t = d1[v] + 1;
    		if (t >= d1[u]) {
    			d2[u] = d1[u];
    			d1[u] = t;
    			son[u] = v;
    		} else if (t > d2[u]) {
    			d2[u] = t;
    		}
    	}
    };
    dfs1(0, -1, 0);
    std::function<void(int, int)> dfs2 = [&](int u, int fa) {
    	for (auto& v : g[u]) {
    		if (v == fa) continue;
    		if (son[u] == v) {
    			up[v] = std::max(up[u], d2[u]) + 1;
    		} else {
    			up[v] = std::max(up[u], d1[u]) + 1;
    		}
    		dfs2(v, u);
    	}
    };
    dfs2(0, -1);
    ll ans = 0;


    for (int i = 0; i < n; ++i) {
    	ans = std::max(ans, 1LL * k * std::max({d1[i], d2[i], up[i]}) - 1LL * c * dep[i]);
    }
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
