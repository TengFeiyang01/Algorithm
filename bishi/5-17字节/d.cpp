#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    auto check = [&](i64 x) {
    	i64 cnt = 0;
    	for (int i = 1; i < n; ++i) {
    		int d = abs(a[i] - a[i - 1]);
    		cnt += (d - 1) / x;
    	}
    	return cnt <= k;
    };

    i64 l = 0, r = 1e10;
    while (l < r) {
    	i64 mid = l + r >> 1;
    	if (check(mid)) {
    		r = mid;
    	} else {
    		l = mid + 1;
    	}
    }
    
    std::cout << l << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
