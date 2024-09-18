#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int ans = n;
    for (int i = 2; i <= n / i; ++i) {
    	if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
    	}
    }
    if (n > 1) ans = ans / n * (n - 1);
    std::cout << ans << "\n";
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
