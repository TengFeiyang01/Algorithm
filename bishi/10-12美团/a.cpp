#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, ans = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	int odd = 0, s = 0;
    	while (x) {
    		if ((x % 10) % 2) {
    			odd++;
    		}
    		s += x % 10;
    		x /= 10;
    	}
    	if (s % 2 == 0 and odd) {
    		ans++;
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
