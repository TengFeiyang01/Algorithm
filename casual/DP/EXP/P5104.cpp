#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int mod = 1000000007;

i64 qpow(i64 x, i64 y) {
    i64 res = 1;
    for (; y; y /= 2, x = x * x % mod)
        if (y & 1)
            res = res * x % mod;
    return res;
}

void solve() {
	i64 n, w, k;
	std::cin >> w >> n >> k;
	std::cout << w * qpow(qpow(2LL, k), mod - 2) % mod;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
