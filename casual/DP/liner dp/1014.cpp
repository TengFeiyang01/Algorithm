#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
    std::vector<i64> dp(n << 2 | 1);

    i64 s = 1, res = 0;
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
    	std::vector<i64> ndp(n << 2 | 1);
    	for (int j = 1; j <= 4 * i; ++j) {
            for (int k = j - 1; k >= std::max(j - 4, 0); --k) {
                ndp[j] += dp[k];
            }
    	}
    	s *= 4;
        dp.swap(ndp);
    }
    for (int i = 3 * n; i <= 4 * n; ++i) {
        res += dp[i];
    }

    i64 g = std::__gcd(s, res);
    std::cout << res / g << "/" << s / g;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
