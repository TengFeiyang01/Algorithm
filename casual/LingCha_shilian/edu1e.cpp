#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

int dp[50][50][51];

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::function<int(int, int, int)> dfs = [&](int x, int y, int z) {
    	if (dp[x][y][z] != -1) return dp[x][y][z];
    	if (x * y == z or !z) return 0;
    	int res = inf;
    	for (int i = 1; i <= x / 2; ++i) {
    		for (int j = 0; j <= z; ++j) {
    			res = std::min(res, y * y + dfs(i, y, j) + dfs(x - i, y, z - j));
    		} 
    	}
    	for (int i = 1; i <= y / 2; ++i) {
    		for (int j = 0; j <= z; ++j) {
    			res = std::min(res, x * x + dfs(x, i, j) + dfs(x, y - i, z - j));
    		}
    	}
    	return dp[x][y][z] = res;
    };
    std::cout << dfs(a, b, c) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    memset(dp, -1, sizeof dp);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
