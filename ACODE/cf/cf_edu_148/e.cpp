#include <bits/stdc++.h>

using ll = long long;
constexpr int P = 998244353;

void solve() {
    int n, x, y, m, k;
    std::cin >> n;
    
    std::vector<int> a(n);
    std::cin >> a[0] >> x >> y >> m >> k;
    
    for (int i = 1; i < n; i++) {
        a[i] = (1LL * a[i - 1] * x + y) % m;
    }
    	
    for (int i = 0; i <= k; ++i) {
    	for (int j = 1; j < n; ++j) {
    		a[j] = (a[j] + a[j - 1]) % P;
        }
    }
    ll ans = 0;

    for (int i = k - 1; i < n; ++i) {
    	ans ^= 1LL * (i + 1) * a[i - k + 1];
    }
    
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
