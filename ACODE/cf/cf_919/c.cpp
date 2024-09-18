#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    auto get = [&](int k) {
    	int g = 0;
    	for (int i = 0; i < n - k; ++i) {
    		g = std::__gcd(g, abs(a[i + k] - a[i]));
    	}
    	return g != 1;
    };

    int ans = 0;
    for (int i = 1; i * i <= n; ++i) {
    	if (n % i) continue;
    	ans += get(i);
    	if (i * i != n) {
    		ans += get(n / i);
    	}
    }
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
