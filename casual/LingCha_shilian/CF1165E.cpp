#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n), b(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	a[i] *= i64(n - i) * (i + 1);
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    }
    std::ranges::sort(a, std::greater());
    std::ranges::sort(b);
    const int mod = 998244353;
    
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
    	ans = (ans + a[i] % mod * b[i]) % mod;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
