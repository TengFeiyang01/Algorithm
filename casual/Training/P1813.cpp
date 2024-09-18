#include <bits/stdc++.h>
 
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n + 2), c(n + 2);
    std::vector<std::array<int, 3>> b(m);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
    	c[i] = a[i] - a[i - 1];
    }

    for (auto&[d, s, t] : b) {
    	std::cin >> d >> s >> t;
    }

    auto check = [&](int k) {
    	auto dif = c;
        //当k大于数组长度的时候，需要防止越界
    	for (int i = 0; i < std::min(m, k); ++i) {
    		auto[d, s, t] = b[i];
    		dif[s] -= d;
    		dif[t + 1] += d;
    	}
    	for (int i = 1; i <= n; ++i) {
    		dif[i] += dif[i - 1];
    		if (dif[i] < 0) {
    			return false;
    		}
    	}
    	return true;
    };

    int l = 0, r = n;
    while (l < r) {
    	int mid = l + r + 1 >> 1;
    	if (check(mid)) {
    		l = mid;
    	} else {
    		r = mid - 1;
    	}
    }
    if (l >= n) {
        std::cout << "0";
    } else {
        std::cout << "-1\n" << l + 1;
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
