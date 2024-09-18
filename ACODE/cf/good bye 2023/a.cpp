#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    i64 s = 1;
    for (int i = 0; i < n; ++i) {
    	i64 x;
    	std::cin >> x;
    	s *= x;
    }
    if (2023 % s) {
    	std::cout << "NO\n";
    } else {
    	if (s != 2023 and k == 0) {
	    	std::cout << "NO\n";
    	} else {
    		std::cout << "YES\n";
    		std::cout << 2023 / s << " ";
    		for (int i = 0; i < k - 1; ++i) {
    			std::cout << 1 << " ";
    		}
            std::cout << "\n";
    	}
    }
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
