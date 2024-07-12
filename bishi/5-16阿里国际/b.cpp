#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int mod = 1000000007;

i64 qpow(int x, i64 y) {
    i64 res = 1;
    for (; y; y /= 2, x = x * x % mod)
        if (y & 1)
            res = res * x % mod;
    return res;
}

void solve() {
	i64 n;
	std::cin >> n;
	std::cout << (n - 1) * qpow(2, n - 2) % mod;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
