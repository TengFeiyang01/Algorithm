#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    auto t = s;
    std::ranges::sort(s);
    if (s[0] == s.back()) {
    	std::cout << "NO\n";
    } else {
    	std::cout << "YES\n";
    	if (s == t) {
    		int n = s.size();
    		std::swap(s[0], s[n - 1]);
    	}
    	std::cout << s << "\n";
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
