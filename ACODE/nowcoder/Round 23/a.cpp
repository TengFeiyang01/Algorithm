#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int a, b;
    std::cin >> a >> b;
    if (b <= a) {
    	std::cout << "-1 -1\n";
    	return;
    }
    std::cout << 1 << " " << b - a << "\n";
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
