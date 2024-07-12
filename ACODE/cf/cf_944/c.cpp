#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;


void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (a > b) {
    	std::swap(a, b);
    }
    if (c > d) {
    	std::swap(d, c);
    }
    if ((a < c and b > d) or (c < a and d > b) or (b < c or d < a)) {
    	std::cout << "NO\n";
    } else {
    	std::cout << "YES\n";
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
