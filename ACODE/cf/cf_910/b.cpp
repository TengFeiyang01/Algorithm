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
    i64 ans = 0;
    for (int i = n - 2; i >= 0; --i) {
    	if (a[i] > a[i + 1]) {
            int x = (a[i] - 1) / a[i + 1]; // 下取整
            ans += x; // 操作次数
            a[i] = a[i] / (x + 1);  // 当前数应该是下取整
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