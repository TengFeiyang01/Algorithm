#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, k, x;
    std::cin >> n >> k >> x;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    auto check = [&](i64 t) {
    	i64 cnt = 0;
    	for (i64 y : a) {
    		if (y > t) {
                cnt += (y - t + x - 1LL) / x;
    		}
    	}
    	return cnt <= k;
    };

    i64 l = -k * x, r = a.back();
    while (l < r) {
    	i64 mid = l + r >> 1;
    	if (check(mid)) {
    		r = mid;
    	} else {
    		l = mid + 1;
    	}
    }
    std::cout << r  << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
