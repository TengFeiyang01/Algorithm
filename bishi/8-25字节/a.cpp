#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    i64 s = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	s += a[i];
    }
    std::sort(a.begin(), a.end());
    i64 ans = 1e18;
    for (int i = 0; i < n - 1; ++i) {
    	i64 x = a[i];
    	// x*k + y*k <= s-y-x
    	// (x+y)*(k+1) <= s
    	// y*(k+1) <= s-x*(k+1)

    	int l = i + 1, r = n - 1;
    	while (l < r) {
    		int mid = l + r + 1 >> 1;
    		i64 y = a[mid];
    		if (x * k + y * k < s - y - x) {
    			l = mid;
    		} else {
    			r = mid - 1;
    		}
    	}
    	// 左侧等于
    	if (l < n and l > i) {
    		i64 y = a[l];
    		ans = std::min(ans, abs(s - (k + 1) * (x + y)));
    	}
    	if (l < n and l > i + 1) {
    		i64 y = a[l - 1];
    		ans = std::min(ans, abs(s - (k + 1) * (x + y)));
    	}

    	l = i + 1, r = n;
    	while (l < r) {
    		int mid = l + r + 1 >> 1;
    		i64 y = a[mid];
    		if (x * k + y * k <= s - y - x) {
    			l = mid;
    		} else {
    			r = mid - 1;
    		}
    	}
    	if (l < n and l > i) {
    		i64 y = a[l];
    		ans = std::min(ans, abs(s - (k + 1) * (x + y)));
    	}
    	if (l + 1 < n) {
    		i64 y = a[l + 1];
    		ans = std::min(ans, abs(s - (k + 1) * (x + y)));
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
