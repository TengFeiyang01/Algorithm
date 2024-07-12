#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, x;
    std::string s;
    std::cin >> n >> s >> x;
    if (s == "B") {
    	std::cout << n / x << "\n";
    } else if (s == "KB") {
    	std::cout << 1024 * n / x << "\n";
    } else {
    	std::cout << 1024 * 1024 * n / x << "\n";
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
