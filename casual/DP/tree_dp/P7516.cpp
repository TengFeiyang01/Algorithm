#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> ans(m + 2);
    std::vector<std::pair<int, int>> edges(m);
    std::vector ok(n, std::vector(n, 0));
    for (int i = 0; i < m; ++i) {
    	auto &[u, v] = edges[i];
    	std::cin >> u >> v;
    	--u, --v;
    	ok[u][v] = i + 1;
    }

    // 统计的是 (x, y) 经过 >= x 的点相互到达的最晚时间
    // 求后缀和
    for (int k = n - 1; k >= 0; --k) {
    	for (int j = k + 1; j < n; ++j) ans[std::min(ok[k][j], ok[j][k])]++;
    	for (int i = 0; i < n; ++i) {
    		if (!ok[i][k]) continue;
    		int now = ok[i][k]; 
    		for (int j = 0; j < n; ++j) {
    			ok[i][j] = std::max(ok[i][j], std::min(now, ok[k][j]));
    		}
    	}
    }
    ans[m + 1] += n;
    for (int i = m; i >= 1; --i) {
    	ans[i] += ans[i + 1];
    }
    for (int i = 1; i <= m + 1; ++i) {
    	std::cout << ans[i] << " \n"[i == m + 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
