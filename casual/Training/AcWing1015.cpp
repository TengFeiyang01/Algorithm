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

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e2 + 13;
int n, m, nums[N][N];

void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    	for (int j = 1; j <= m; ++j) 
    		std::cin >> nums[i][j];
	int dp[2][N]{0};
    for (int i = 1; i <= n; ++i)
    	for (int j = 1; j <= m; ++j) {
            dp[i & 1][j] = std::max(dp[i & 1][j - 1], dp[(i - 1) & 1][j]) + nums[i][j];
        }
        
    std::cout << dp[n & 1][m] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
