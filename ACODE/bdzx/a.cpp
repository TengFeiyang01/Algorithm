#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n), b(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    }
    i64 l, r, c;
    std::cin >> l >> r >> c;

    auto check = [&](i64 t) {
    	i64 cnt = 0;
    	t = std::min(t, r);
    	for (int i = 0; i < n; ++i) {
    		if (t >= l and b[i] <= t) {
    			cnt += (t - b[i] + 1 + a[i] - 1) / a[i];
    			// std::cout << t << " " << a[i] << " " << b[i] << " " << (t - b[i] + a[i] - 1) / a[i] << " ";
    			if (b[i] < l) {
    				cnt -= (l - b[i] + a[i] - 1) / a[i];
    				// std::cout << (l - 1 - b[i] + a[i] - 1) / a[i] << "\n";
    			}
    		}
    	}
    	// std::cout << t << " " << cnt << "\n";
    	return cnt >= c;
    };

    i64 lo = 1, hi = 2e18;
    while (lo < hi) {
    	i64 mid = lo + hi >> 1;
    	if (check(mid)) {
    		hi = mid;
    	} else {
    		lo = mid + 1;
    	}
    }
    if (lo < 2e18) {
    	std::cout << lo << "\n";
    } else {
    	std::cout << "-1\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
