#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    if (k >= 3) {
        // 因为可以构造 a-b a-b (a-b)-(a-b) = 0
    	std::cout << "0\n";
    	return;
    }
    i64 ans = std::ranges::min(a);
    if (k == 1) {
    	for (int i = 0; i < n; ++i) {
    		for (int j = i + 1; j < n; ++j) {
    			ans = std::min(ans, abs(a[i] - a[j]));
    		}
    	}
    	std::cout << ans << "\n";
    } else {
    	std::vector<i64> d;
		for (int i = 0; i < n; ++i) {
    		for (int j = i + 1; j < n; ++j) {
    			ans = std::min(ans, abs(a[i] - a[j]));
    			d.push_back(abs(a[i] - a[j]));
    		}
    	}
    	std::ranges::sort(d);

    	for (int i = 0; i < n; ++i) {
    		int j = std::ranges::lower_bound(d, a[i]) - d.begin();
    		if (j < d.size()) ans = std::min(ans, abs(d[j] - a[i]));
    		if (j) ans = std::min(ans, abs(a[i] - d[j - 1]));
    		
    	}
    	std::cout << ans << "\n";
    }
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
