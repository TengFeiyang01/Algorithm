#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int m = 2 * n - 1, neg = 0;
    std::vector<i64> a(2 * n - 1);
    for (int i = 0; i < m; ++i) {
    	std::cin >> a[i];
    	neg += a[i] < 0;
    }
    i64 ans = 0, mn = inf;
    for (int i = 0; i < m; ++i) {
    	ans += std::max(a[i], -a[i]); 
    	mn = std::min(mn, abs(a[i]));
    }
    if (n % 2 == 0 and neg == m) {
    	ans -= 2 * mn;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
