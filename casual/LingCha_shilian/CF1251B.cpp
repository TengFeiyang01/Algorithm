#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int one = 0, zero = 0, odd = 0;
    for (int i = 0; i < n; ++i) {
    	std::string s;
    	std::cin >> s;
    	one += std::ranges::count(s, '1');
    	zero += std::ranges::count(s, '0');
    	if (s.size() % 2) {
    		odd++;
    	}
    } 
    if (!odd and one % 2 and zero % 2) {
    	std::cout << n - 1 << "\n";
    } else {
    	std::cout << n << "\n";
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
