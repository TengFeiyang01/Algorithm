#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;



void solve() {
	i64 x, y, z, n;
    std::cin >> n >> x >> y >> z;
    std::vector<i64> a(n);
    i64 ans = 1e18;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    
    ans = std::min(y * n, x * n);
    for (int l = 0; l < n; ++l) {
    	i64 t = 0;
    	for (int r = l; r < n; ++r) {
    		t = std::max(t, a[r]);
    		ans = std::min(ans, l * x + t * z + (n - r - 1) * y);
    	}
    }
    std::cout << ans << "\n";
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
