#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    if (n <= 6 or n == 9) {
    	std::cout << "NO\n";
    } else {
    	--n;
    	std::cout << "YES\n";
    	std::cout << 1 << " ";
    	for (int i = 2; i <= n; ++i) {
    		if (i % 3 and (n - i) % 3) {
    			std::cout << i << " " << n - i << "\n";
                break;
    		}
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