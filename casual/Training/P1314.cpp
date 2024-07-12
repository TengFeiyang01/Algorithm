#include <bits/stdc++.h>

using i64 = long long; 

void solve() {
    int n, m;
    i64 s;
    std::cin >> n >> m >> s;
    std::vector<std::array<i64, 2>> c(m), a(n + 1);

    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i][0] >> a[i][1];
    }

    for (auto&[l, r] : c) {
    	std::cin >> l >> r;
    }

    i64 ans = 1e18, dif;

    /*
        1、 二分 w 的值，显然当前的 y 是随着 w 的变化而变化的，w 越大，y越小。
        2、 前缀和 每次求的是区间和的乘积
    */

    auto check = [&](int w) {
    	i64 cur = 0;
	    std::vector<std::array<i64, 2>> presum(n + 2);
    	for (int i = 1; i <= n; ++i) {
    		presum[i][0] += presum[i - 1][0];
    		presum[i][1] += presum[i - 1][1];
    		if (a[i][0] >= w) {
    			presum[i][0] += 1LL;
    			presum[i][1] += a[i][1];
    		}
    	}
    	for (auto&[l, r] : c) {
    		cur += (presum[r][0] - presum[l - 1][0]) * (presum[r][1] - presum[l - 1][1]); 
    	}
    	dif = abs(cur - s);
    	if (cur > s) return true;
    	else return false;
    };

    int l = 0, r = 1e6;
    while (l < r) {
    	int mid = l + r + 1 >> 1;
    	if (check(mid)) {
    		l = mid;
    	} else {
    		r = mid - 1;
    	}
    	ans = std::min(ans, dif);
    }
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
