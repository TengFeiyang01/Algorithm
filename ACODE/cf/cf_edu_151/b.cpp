#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int x1, x2, x3, y1, y2, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (x1 >= x2 == x1 <= x3) {
    	if (y1 <= y2 == y1 <= y3) {
    		std::cout << 1 + std::min(abs(y1 - y2), abs(y1 - y3)) << "\n";
    	} else {
    		std::cout << 1 << "\n";
    	}
    } else if (y1 >= y2 == y1 <= y3) {
    	if (x1 <= x2 == x1 <= x3) {
    		std::cout << 1 + std::min(abs(x1 - x3), abs(x1 - x2)) << "\n";
    	} else {
    		std::cout << 1 << "\n";
    	}
    } else {
    	std::cout << 1 + std::min(abs(y1 - y2), abs(y1 - y3)) + std::min(abs(x1 - x3), abs(x1 - x2)) << "\n";
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
