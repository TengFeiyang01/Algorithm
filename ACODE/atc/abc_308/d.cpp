#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    for (auto &x : s) std::cin >> x;
    std::vector st(n, std::vector<bool>(m, false));
	if (s[0][0] != 's') {
		std::cout << "No\n";
		return;
	}
	int dirs[] = {-1, 0, 1, 0, -1};
	std::string t = "snuke";
	int dp[501][501]{0};
	std::function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool {
		if (i == n - 1 and j == m - 1) return true;
		dp[i][j] = 1;
		for (int a = 0; a < 4; ++a) {
			int x = i + dirs[a], y = j + dirs[a + 1];
			if (x < 0 or y < 0 or x >= n or y >= m or s[x][y] != t[(k + 1) % 5] or dp[x][y]) continue;
			if (dfs(x, y, k + 1)) return true;
		}
		return false;
	};

	if (dfs(0, 0, 0)) std::cout << "Yes\n";
	else std::cout << "No\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}