#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 x, y;
    i64 a, b;
    std::cin >> x >> y;
    i64 c = y * x;
    for (i64 i = 1; i * i <= c; ++i) {
    	if (c % i == 0) {
    		// 这就是符合答案的某对 a， b
    		i64 j = c / i;
    		if (std::__gcd(i, j) == x and std::lcm(i, j) == y) {
    			std::cout << i << " " << j << "\n";
    			return;
    		}
    	}
    }
    std::cout << "-1\n";
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
