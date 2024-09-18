#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    i64 s = 0, odd = 0, x;
    for (int i = 0; i < n; ++i) {
    	std::cin >> x;
    	s += x;
    	odd += x & 1;

    	if (i == 0) {
    		std::cout << x << " ";
    		continue;
    	}
    	i64 tmp = odd / 3;
    	if (odd % 3 == 1) {
    		tmp++;
    	}
    	std::cout << s - tmp << " ";
    }
    std::cout << "\n";
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
