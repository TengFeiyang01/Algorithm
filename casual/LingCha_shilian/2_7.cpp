#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cmath>
 
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
const int N = 4e5 + 1;
/*

https://atcoder.jp/contests/arc111/submissions/38552445

把每行的两个数当作图的一条边的两个端点。

对每个连通块分别统计。
如果连通块是树，那么答案是边数。
如果连通块不是树，那么答案是点数。
*/

void solve() {
	int n, cntE = 0, cntV = 0, ans = 0;
    std::cin >> n;   
	std::vector g(N, std::vector<int>());
	
	while (n--) {
		int a, b;
		std::cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	std::vector<bool> vis(N, 0);
	

	std::function<void(int)> dfs = [&](int v) ->void {
		vis[v] = true;
		cntV++;
		cntE += sz(g[v]);
		for (int u : g[v]) {
			if (!vis[u])
				dfs(u);
		}
	};

	for (int i = 0; i < N; ++i) {
		if (!vis[i] && !g[i].empty()) {
			cntE = 0, cntV = 0;
			dfs(i);
			ans += std::min(cntV, cntE / 2);
		}
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
