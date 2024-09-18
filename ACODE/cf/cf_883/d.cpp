#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, d, h;
    std::cin >> n >> d >> h;
    long double ans = 1.0 * n * d * h / 2;
    
    for (int i = 0, pre = -1, y; i < n; ++i) {
    	std::cin >> y;
    	if (pre != -1) {
    		if (pre + h > y) {
    			long double dh = h - (y - pre);
    			long double dd = 1.0 * d * (dh / h);
                ans -= dh * dd / 2;
    		}
    	}
    	pre = y;
    }
    std::cout << std::fixed << std::setprecision(7) << ans << "\n";
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
