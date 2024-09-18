#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, ll>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<PII> g[n];
    std::vector<int> deg(n);
    for (int i = 1; i < n; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	--u, --v;
    	g[u].emplace_back(v, w);
    	g[v].emplace_back(u, w);
    	deg[u]++;
    	deg[v]++;
    }
    std::vector<ll> f(n);

    std::function<void(int, int, int)> dfs = [&](int u, int p, int d) {
    	int ans = 0;
    	for (auto [v, w] : g[u]) {
    		if (v == p) continue;
    		dfs(v, u, d);
            ans++;
    		if (w <= d) {
    			f[u] += std::min(f[v], w);
    		} else {
    			f[u] += f[v];
    		}
    	}
    	if (ans == 0) {
    		f[u] = inf;
    	}
    };

    int l = 1, r = inf;

    while (l < r) {
        int mid = l + r >> 1;
        f.assign(n, 0);
        dfs(0, -1, mid);
        if (f[0] <= m) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    if (l > N) l = -1;
    std::cout << l;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
