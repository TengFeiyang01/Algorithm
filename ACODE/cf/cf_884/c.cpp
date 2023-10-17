#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n), s(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	s[i] = a[i];
    	if (i) s[i] += s[i - 1];
    }
    if (n == 1) {
    	std::cout << a[0] << "\n";
    	return;
    }
    if (n == 2) {
    	std::cout << std::max(a[0], a[1]) << "\n";
    	return;
    }
    std::vector<i64> dp(n);  //dp[i] 保留第i个
    dp[0] = a[0];
    dp[1] = a[1];
    i64 mx0 = dp[0], mx1 = dp[1];
    for (int i = 2; i < n; ++i) {
    	if (i & 1) {
    		dp[i] = std::max(0LL, mx1) + a[i];
    		mx1 = std::max(mx1, dp[i]);
    	} else {
    		dp[i] = std::max(0LL, mx0) + a[i];
    		mx0 = std::max(mx0, dp[i]);
    	}
    }
    std::cout << std::max(mx0, mx1) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
