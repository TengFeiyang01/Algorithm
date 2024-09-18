#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 a, k;
    std::cin >> a >> k;
    i64 p = 1;
    for (int i = 0; i < k; ++i) {
    	p *= 10LL;
    }
    p -= a;
    i64 g = std::__gcd(a, p);
    a /= g;
    p /= g;
    if (a % p == 0) {
    	std::cout << a / p << "\n";
    } else {
    	std::cout << a << "/" << p << "\n"; 
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
