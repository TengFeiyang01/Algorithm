#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(4);
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	a[x]++;
    }
    std::vector dp(n + 2, std::vector(n + 2, std::vector<long double>(n + 2)));

    dp[0][0][0] = 0;

    for (int i = 0; i <= n; ++i) {
    	for (int j = 0; j <= n; ++j) {
    		for (int k = 0; k <= n; ++k) {
    			if (i or j or k) {
    				dp[i][j][k] = 1.0 * (n - i - j - k) / (i + j + k);
    				if (i) dp[i][j][k] += 1.0 * i / (i + j + k) * (dp[i - 1][j + 1][k] + 1);
    				if (j) dp[i][j][k] += 1.0 * j / (i + j + k) * (dp[i][j - 1][k + 1] + 1);
    				if (k) dp[i][j][k] += 1.0 * k / (i + j + k) * (dp[i][j][k - 1] + 1);
    			}
    		}
    	}
    }
    std::cout << std::setprecision(11) << dp[a[3]][a[2]][a[1]] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
