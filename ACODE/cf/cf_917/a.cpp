#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int m = 0, zero = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	if (a[i] < 0) {
    		m++;
    	}
    	zero += a[i] == 0;
    }
    if (zero) {
    	std::cout << "0\n";
    	return;
    }
   	if (m % 2 == 0) {
   		std::cout << 1 << "\n";
   		std::cout << 1 << " " << 0 << "\n";
   	} else {
   		std::cout << 0 << "\n";
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
