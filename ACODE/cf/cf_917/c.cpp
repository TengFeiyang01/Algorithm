#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k, d;
    std::cin >> n >> k >> d;
    std::vector<int> a(n + 1), v(k);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < k; ++i) {
    	std::cin >> v[i];
    }
    // 考虑枚举第一次收的时机？ 只可能是1-n*2的某一天
    // 因为初始分值最多为n 超过2*n的话 我还不如直接一收一发
    int ans = -inf, now = 0;
    for (int i = 0; i < std::min(d, 2 * n); ++i) {
    	int x = 0;
    	for (int j = 1; j <= n; ++j) x += a[j] == j;
    	ans = std::max(ans, x + (d - i - 1) / 2);
    	for (int j = 1; j <= v[i % k]; ++j) a[j]++;
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
