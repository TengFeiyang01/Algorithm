#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    i64 x;
    std::cin >> n >> k >> x;

    i64 down = (1LL + k) * k / 2;
    i64 up = (n + n - k + 1LL) * k / 2;

    if (down > x or x > up) {
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