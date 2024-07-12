#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    i64 n;
    std::cin >> s >> n;
    i64 ans = 0;
    int m = s.size();
    for (int i = 0; i < s.size(); ++i) {
    	if (s[i] == '1') {
    		ans |= 1LL << (m - i - 1);
    	}
    }
    if (ans > n) {
        std::cout << -1 << "\n";
        return;
    }
    for (int i = 0; i < m; ++i) {
    	if (s[i] == '?') {
    		if (ans + (1LL << (m - i - 1)) <= n) {
    			ans += 1LL << (m - i - 1);
    		}
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}