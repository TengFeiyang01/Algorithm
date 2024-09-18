#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	int cnt = 0, x;
    	std::cin >> x;
    	for (int i = 2; i * i <= x; ++i) {
    		while (x % i == 0) {
    			x /= i;
    			cnt++;
    		}
    	}
    	if (x > 1) {
    		cnt++;
    	}
    	ans += cnt >= 3;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
