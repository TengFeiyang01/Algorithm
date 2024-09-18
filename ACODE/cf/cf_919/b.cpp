#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k, x;
    std::cin >> n >> k >> x;
    std::vector<int> a(n);
    i64 s = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
        s += a[i];
    }
    // 考虑 x + y 不删除 y
    // 考虑枚举删除了多少个
	std::ranges::sort(a);
	
    i64 neg = 0;
    for (int i = n - 1, j = 0; j < x; j++, i--) {
        neg += a[i];
        s -= a[i];
    }

    i64 ans = s - neg;

    for (int i = n - 1, j = 0; j < k; j++, i--) {
        if (i - x >= 0) {
            s -= a[i - x];
            neg += a[i - x];
        }
        neg -= a[i];
        ans = std::max(ans, s - neg);
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
//3 3 3 7 15 32
