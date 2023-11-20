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
    int n, m;
    std::cin >> n >> m;
	std::string g[n];
	for (int i = 0; i < n; ++i) std::cin >> g[i];
	int ans = 0;
	
	std::function<void(int, int)> dfs = [&](int x, int y) ->void {
        if (x < 0 || y < 0 || x >= n || y >= m || g[x][y] == '.') return;
        g[x][y] = '.';
        dfs(x + 1, y);
        dfs(x + 1, y + 1);
        dfs(x - 1, y - 1);
        dfs(x - 1, y + 1);
        dfs(x + 1, y - 1);
        dfs(x, y + 1);
        dfs(x - 1, y);
        dfs(x, y - 1);
	};
	

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (g[i][j] == 'W') {
				ans++;
				dfs(i, j);

			}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
