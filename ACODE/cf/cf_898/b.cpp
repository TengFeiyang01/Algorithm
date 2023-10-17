#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 tot = 1, ans = 0;
   	i64 n;
   	std::cin >> n;
    std::vector<i64> a(n), b(n + 1, 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        b[i] = b[i + 1] * a[i];
    }
    
    for (int i = 0; i < n; ++i) {
        ans = std::max(ans, tot * (a[i] + 1) * b[i + 1]);
        tot *= a[i];
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