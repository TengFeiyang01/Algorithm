#include <bits/stdc++.h>

using i64 = long long;

/*
	自底向上思考。

	每个叶子由于下界 >=1，所以一定要操作，由于序列是递增的，那么尽量取范围的上界，祖先节点的增量可以没叶子这么多。

	对于一个非叶节点，累加所有子节点的增量。如果小于下界，那么必须操作一次，变成上界。如果大于上界则免费调整为上界。
*/

void solve() {
    int n, x;
    std::cin >> n;
    std::vector<int> g[n];
    for (int i = 1; i < n; ++i) {
    	std::cin >> x;
    	g[x - 1].emplace_back(i);
    }
    std::vector<std::array<i64, 2>> lim(n);
    for (auto&[l, r] : lim) std::cin >> l >> r;

    int ans = 0;
	std::function<i64(int)> dfs = [&](int u) ->i64 {
		i64 s = 0;
		for (auto &v : g[u]) {
			s += dfs(v);
		}
		if (s < lim[u][0]) {
			ans++;
			s = lim[u][1];
		} else if (s > lim[u][1]) {
			s = lim[u][1];
		}
		return s;
	};
	dfs(0);
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
