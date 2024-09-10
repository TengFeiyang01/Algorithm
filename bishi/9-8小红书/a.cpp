#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

const int mod = 1000000007;

i64 qpow(i64 x, i64 y) {
    i64 res = 1;
    for (; y; y /= 2, x = x * x % mod)
        if (y & 1)
            res = res * x % mod;
    return res;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    i64 ans = 0, s = 0;
    i64 tot = 0;
    for (int i = 0, x; i < n; ++i) {
    	std::cin >> x;
    	s = std::max(s, s + x);
    	ans = std::max(ans, s);
    	tot += x;
    }
    std::cout << ((tot - ans + ans * qpow(2, k)) % mod + mod)  % mod << "\n";
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
