#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    i64 cost;
    std::cin >> n >> cost;

    std::vector<i64> a(n), b(n); 
    int n = a.size();
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    }

    auto check = [&](i64 x) {
    	i64 c = 0;
    	for (int i = 0; i < n; ++i) {
    		if (a[i] < x) {
    			c += (x - 1) / a[i] * b[i];
    			if (c > cost) {
    				return false;
    			}
    		}
    	}
    	return c <= cost;
    };

    i64 l = 0, r = 1e9;
    while (l < r) {
    	i64 mid = l + r + 1 >> 1;
    	if (check(mid)) {
    		l = mid;
    	} else {
    		r = mid - 1;
    	}
    }
    return l;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
