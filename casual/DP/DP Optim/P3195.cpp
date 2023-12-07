#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, l;
    std::cin >> n >> l;
    std::vector<i64> s(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> s[i];
    	s[i] += s[i - 1];
    }
    // a[i] = s[i] + i  
    // b[i] = s[i] + i + l - 1
    // dp[i] = dp[j] + (s[i] + i - (s[j] + j + l - 1)) ^ 2
    //       = dp[j] + (a[i] - b[j]) ^ 2
    //       = dp[j] + a[i]^2 - 2*a[i]*b[j] + b[j]^2
    // dp[j] + b[j]^2 = 2*a[i]*b[j] + dp[i] - a[i]^2
    // dp[i] 视为斜率固定 过点 (b[j], dp[j] + b[j]^2) 斜率为2*a[i] 直线的最下截距再减去常量
    // 那么维护之前的点的下凸包即可
    std::vector<i64> q(n + 2), dp(n + 1);

    auto a = [&](int i) { return s[i] + i; };
    auto b = [&](int i) { return a(i) + l + 1LL; };
    auto y = [&](int i) { return dp[i] + b(i) * b(i); };
    auto x = [&](int i) { return b(i); };

    auto slope = [&](int i, int j) {
    	return double(y(i) - y(j)) / (x(i) - x(j)); 
    };

    int hh = 0, tt = 0;
    for (int i = 1; i <= n; ++i) {
    	while (hh < tt and slope(q[hh], q[hh + 1]) < 2 * a(i)) hh++;
    	int j = q[hh];
    	dp[i] = dp[j] + (a(i) - b(j)) * (a(i) - b(j));
        // 队尾两点斜率大于当前点和队尾 队尾出队
    	while (hh < tt and slope(q[tt], q[tt - 1]) > slope(q[tt], i)) --tt;
    	q[++tt] = i;
    }
    
    std::cout << dp[n] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
