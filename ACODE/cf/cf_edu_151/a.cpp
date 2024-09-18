#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, k, x;
    std::cin >> n >> k >> x;
    if (x != 1) {
    	std::cout << "YES\n";
    	std::cout << n << "\n";
    	for (int i = 1; i <= n; ++i) std::cout << 1 << " \n"[i == n];
    } else {
    	if (k == 1) {
    		std::cout << "NO\n";
    	} else if (k == 2) {
    		if (n % 2) {
    			std::cout << "NO\n";
    		} else {
    			std::cout << "YES\n";
    			std::cout << n / 2 << "\n";
    			for (int i = 0; i < n / 2; ++i) std::cout << 2 << " \n"[i == n / 2 - 1];
    		} 
    	} else {
    		std::cout << "YES\n";
    		if (n % 2) {
                n -= 3;
                std::cout << (1 + n / 2) << "\n";
    			std::cout << 3 << " ";
    			for (int i = 0; i < n / 2; ++i) std::cout << 2 << " \n"[i == n / 2 - 1];
    		} else {
    			std::cout << n / 2 << "\n";
    			for (int i = 0; i < n / 2; ++i) std::cout << 2 << " \n"[i == n / 2 - 1];
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
