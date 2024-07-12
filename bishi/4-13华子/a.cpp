#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::vector<int> a(10);
    int n = 10, tot = 0;
    for (int i = 0; i < 10; ++i) {
    	std::cin >> a[i];
    	tot += a[i];
    }
    int ans = inf;
    for (int i = 0; i < 1 << 10; ++i) {
    	int cnt = 0, s = 0;
    	for (int j = 0; j < 10; ++j) {
    		if (i >> j & 1) {
    			s += a[j];
    			cnt++;
    		}
    	}
    	if (cnt == 5) {
    		ans = std::min(ans, std::abs(tot - 2 * s));
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
