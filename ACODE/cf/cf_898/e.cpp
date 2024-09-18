#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    //上界限 不能太大
    
    i64 l = 1, r = 1e10;
    while (l < r) {
    	i64 mid = (l + r + 1) / 2;
    	i64 s = 0;
    	for (int i = 0; i < n; ++i) {
            if (a[i] < mid) {
                s += mid - a[i];
            }
        }
    	if (s <= k) {
    		l = mid;
    	} else {
    		r = mid - 1;
    	}
    }
    std::cout << l << "\n";
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