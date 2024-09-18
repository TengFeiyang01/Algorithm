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

const int N = 2e3 + 13;

std::string s;
int f[N][N];
std::vector<int> G[N];
int a[N][N];	//a[x][y] 表示x朝着y走一步的点

//预处理
//起点是x，第一个点是z
void dfs(int u, int fa, int x, int z) {
	a[x][u] = z;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(v, u, x, z);
	}
}

int dp(int x, int y) {
	if (~f[x][y]) return f[x][y];
	if (x == y) return f[x][y] = 1;
	if (s[x] == s[y]) {
		f[x][y] = 2;
		if (a[x][y] != y)
			f[x][y] += dp(a[x][y], a[y][x]);
	} else f[x][y] = std::max(dp(a[x][y], y), dp(x, a[y][x]));
	return f[x][y];
}

void solve() {
	int n;
	std::cin >> n >> s;
	s.insert(0, " ");

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			f[i][j] = -1;
	for (int i = 1; i <= n; ++i) G[i].clear();

    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	G[u].push_back(v);
    	G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
    	for (int j : G[i])
    		dfs(j, i, i, j);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		ans = std::max(ans, dp(i, j));
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    for (int i = 1; i <= _; ++i) solve();

    return 0;
}
