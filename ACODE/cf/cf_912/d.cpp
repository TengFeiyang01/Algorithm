#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> a(n);
    std::vector<i64> sum(64);

    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < q; ++i) {
	    auto b = a;
    	i64 x, ans = 0;
    	std::cin >> x;
    	for (int i = 60; i >= 0; --i) {
    		i64 cost = 0;
    		for (int j = 0; j < n; ++j) {
    			if ((b[j] >> i & 1) == 0) {
    				cost += (1LL << i) - ((1LL << (i + 1)) - 1ll & b[j]);
    			}
	    		if (cost > x) break;
    		}
    		if (cost <= x) {
    			ans |= 1LL << i;
    			x -= cost;
    			for (int j = 0; j < n; ++j) {
    				if ((b[j] & (1ll << i)) == 0) {
    					b[j] = (b[j] | (1ll << i)) & (1ll << i);
    				}
    			}
    		}
    	}
    	std::cout << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
