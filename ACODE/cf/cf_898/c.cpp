#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    int ans = 0;
    for (int i = 0; i < 10; ++i) {
    	std::cin >> s;
    	for (int j = 0; j < 10; ++j) {
    		if (s[j] == 'X') {
                ans += 5 - std::max(std::max(4 - j, j - 5), std::max(4 - i, i - 5));
    		}
    	}
    }
    std::cout << ans << "\n";
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