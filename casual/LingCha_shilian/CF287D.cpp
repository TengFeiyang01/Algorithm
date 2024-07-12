#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    if (n == 1) {
    	std::cout << "0\n";
    } else {
    	i64 l = 1, r = k + 1;
    	while (l < r) {
    		i64 mid = l + r >> 1;
    		if (1 + (2 * k - mid + 1) * mid / 2 - mid >= n) {
    			r = mid;
    		} else {
    			l = mid + 1;
    		}
    	}
    	if (l == k + 1) {
    		std::cout << "-1\n";
    	} else {
    		std::cout << l << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
