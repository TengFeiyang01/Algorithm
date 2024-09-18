#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n), b(m);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
    	std::cin >> b[i];
    }

    std::ranges::sort(a);
    std::ranges::sort(b);

    std::vector<i64> sa(n + 1), sb(m + 1);

    for (int i = 1; i <= n; ++i) {
    	sa[i] = sa[i - 1] + a[i - 1];
    }
    for (int i = 1; i <= m; ++i) {
    	sb[i] = sb[i - 1] + b[i - 1];
    }
    i64 ans = 0;
    for (int i = 0; i <= n; ++i) {
        // 枚举前面选了多少个
        // sa[n] - sa[n - i]        || -sa[n - i]
        // sb[m] -sb[m - n + i]     || -sb[i] 
    	i64 now = sa[n] - sa[n - i] - sa[n - i];
    	now += sb[m] - sb[i] - sb[m - n + i];
    	ans = std::max(ans, now);
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
