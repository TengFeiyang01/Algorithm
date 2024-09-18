#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n * 2);
    for (int i = 0; i < n * 2; ++i) {
    	std::cin >> a[i];
    }
    std::ranges::sort(a);
    int ans = 0;
    
    for (int i = 1; i < n; ++i) {
        ans += a[i + n] - a[i + n - 1] + a[i] - a[i - 1];
    }

    std::cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " " << a[i + n] << "\n";
    }
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
