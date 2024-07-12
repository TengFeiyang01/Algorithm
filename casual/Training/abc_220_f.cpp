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
 	std::vector<long long> sub(n, 1), ans(n);
 	std::vector<int> g[n];
 	for (int i = 1; i < n; ++i) {
 		int u, v;
 		std::cin >> u >> v;
 		u--, v--;
 		g[u].push_back(v);
 		g[v].push_back(u);
 	}

 	std::function<void(int, int, int)> dfs1 = [&](int u, int fa, long long d) {
 		ans[0] += d;
 		for (auto v : g[u]) {
 			if (v != fa) {
 				dfs1(v, u, d + 1ll);
 				sub[u] += sub[v];
 			}
 		}
 	};
 	dfs1(0, -1, 0);

 	std::function<void(int, int)> dfs2 = [&](int u, int fa) {
 		for (auto v : g[u]) {
 			if (v != fa) {
 				ans[v] = ans[u] + n - 2LL * sub[v];
 				dfs2(v, u);
 			}
 		}
 	};
 	dfs2(0, -1);

 	for (int i = 0; i < n; ++i) {
 		std::cout << ans[i] << "\n "[i == n - 1];
 	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
