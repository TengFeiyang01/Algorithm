#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    i64 ans = 0, s = 0, mx = 0, mn = 0;
    //求出最小字段和（画折线图）
	for (auto &x : a) {
		s += x;
		mx = std::max(mx, s);
		if (mx - s > mn) {
			mn = mx - s;
			ans = mx;
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
