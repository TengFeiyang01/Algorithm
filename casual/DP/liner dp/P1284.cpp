#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

bool ok(i64 x,i64 y,i64 z){
	return x + y > z && x + z > y && y + z > x;
}

void solve() {
    int n;
    long double s = 0;
    std::cin >> n;
    std::vector<long double> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	s += a[i];
    }
    std::vector dp(s / 2 + 1, std::vector(s / 2 + 1, 0));
    dp[0][0] = 1;
    for (auto x : a) {
    	for (int j = s / 2; j >= 0; --j) {
    		for (int k = s / 2; k >= 0; --k) {
    			if (j - x >= 0 and dp[j - x][k]) dp[j][k] = 1;
    			if (k - x >= 0 and dp[j][k - x]) dp[j][k] = 1;
    		}
    	}
    }
    long double ans = -1;
    for (int j = s / 2; j > 0; --j) {
    	for (int k = s / 2; k > 0; --k) {
    		if (dp[j][k] and ok(j, k, s - j - k)) {
    			ans = std::max(ans, std::sqrt(s / 2 * (s / 2 - j) * (s / 2 - k) * (s / 2 - (s - k - j))));
    		}
    	}
    }
    if (ans != -1) {
    	std::cout << i64(ans * 100) << "\n";
    } else {
    	std::cout << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
