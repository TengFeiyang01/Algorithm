#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, s = 0;
    std::cin >> n;
    for (int i = 0, x; i < n - 1; ++i) {
    	std::cin >> x;
    	s += x;
    }
    std::cout << -s << "\n";
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