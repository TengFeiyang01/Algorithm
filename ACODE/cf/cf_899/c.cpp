#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (auto &x : a) {
    	std::cin >> x;
    }
    std::vector<i64> suf(n + 1);
    
    for (int i = n - 1; i >= 0; --i) {
    	suf[i] = suf[i + 1] + std::max(0LL, a[i]);
    }

    i64 tot = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            ans = std::max(ans, suf[i + 1] + tot + a[i]);
        } else {
            ans = std::max(ans, suf[i + 1] + tot);
        }
        if (i % 2 == 0)
        	tot += std::max(0LL, a[i]);
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