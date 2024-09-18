#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    int ma = 1;
    for (int i = 2; i <= n; ++i) {
    	if (n % i != 0) {
    		int cur = 0;
    		for (int j = 1; j <= n; ++j, cur++) {
    			std::cout << char('a' + cur % i);
    		}
    		std::cout << "\n";
    		return;
    	}
    }
    int now = 0;
    for (int j = 1; j <= n; ++j, ++now) {
    	std::cout << char('a' + now % n);
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
