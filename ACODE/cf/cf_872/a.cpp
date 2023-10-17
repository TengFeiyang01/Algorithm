#include <bits/stdc++.h>


void solve() {
    int n;
    std::string s;
    std::cin >> s;
    n = s.size();
    int ans = -1;

    // for (int len = n - 1; len >= 2; --len) {
    // 	for (int l = 0; l + len - 1 < n; ++l) {
    // 		int a = l, b = l + len - 1;
    // 		while (a < b) {
    // 			if (s[a++] != s[b--]) {
    //                 ans = std::max(ans, len);
    // 			    break;
    //             }
    // 		}
    // 	}
    // }
    //std::cout << ans << "\n";
    if (s == std::string(n, s[0])) {
        std::cout << "-1\n";
    } else {
        std::cout << n - 1 << "\n";
    }
}


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
