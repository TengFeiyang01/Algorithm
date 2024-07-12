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
    i64 ans = 0, pre = 0;
    std::ranges::reverse(a);
    for (int i = 0; i < n; ++i) {
    	pre += a[i];
        // 第一个元素必须分组 
        if (pre > 0 or i == n - 1) {
            ans += pre;
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
