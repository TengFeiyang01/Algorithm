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
    std::ranges::sort(a);
    i64 ans = 0;
    for (int i = 1; i < n; ++i) {
    	int l = std::ranges::lower_bound(a, a[i]) - a.begin() - 1;
    	int r = std::ranges::upper_bound(a, a[i]) - a.begin();
    	ans += a[i] * l - (n - r - 1) * a[i];
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
