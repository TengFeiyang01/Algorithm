#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n + 2), pre(n + 2), suf(n + 2);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
        pre[i] = a[i] + n - i;
        suf[i] = a[i] + i - 1;
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] = std::max(pre[i - 1], pre[i]);
    }

    for (int i = n; i >= 1; --i) {
        suf[i] = std::max(suf[i + 1], suf[i]);
    }

    i64 ans = 1e18;
    for (int i = 1; i <= n; ++i) {
		ans = std::min(ans, std::max({a[i], suf[i + 1], pre[i - 1]}));
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
