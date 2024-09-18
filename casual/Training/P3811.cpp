#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, p;
    std::cin >> n >> p;
    std::vector<i64> inv(n + 1);
    inv[1] = 1;
    // p = k * i + r
    // 0 === k * i + r (mod p)
    // i^-1 === -k * r ^-1 (mod p)
    // i^-1 === -[p / i] * (p mod i)^-1 (mod p)
    for (int i = 2; i <= n; ++i) {
    	inv[i] = i64(p - p / i) * inv[p % i] % p;
    }
    for (int i = 1; i <= n; ++i) {
    	std::cout << inv[i] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
