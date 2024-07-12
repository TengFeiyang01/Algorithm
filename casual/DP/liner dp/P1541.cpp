#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1), b(5);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
    	int x;
    	std::cin >> x;
    	b[x]++;
    }
    std::vector dp(b[2] + 1, std::vector(b[3] + 1, std::vector(b[4] + 1, 0)));

    for (int i = 0; i <= b[1]; ++i) {
    	for (int j = 0; j <= b[2]; ++j) {
    		for (int k = 0; k <= b[3]; ++k) {
    			for (int q = 0; q <= b[4]; ++q) {
                    int t = a[i + 2 * j + 3 * k + 4 * q + 1];
    				if (j) dp[j][k][q] = std::max(dp[j][k][q], dp[j - 1][k][q]);
    				if (k) dp[j][k][q] = std::max(dp[j][k][q], dp[j][k - 1][q]);
    				if (q) dp[j][k][q] = std::max(dp[j][k][q], dp[j][k][q - 1]);
                    dp[j][k][q] += t;
    			}
    		}
    	}
    }
    std::cout << dp.back().back().back() << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
