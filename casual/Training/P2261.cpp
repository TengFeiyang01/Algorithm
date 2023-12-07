#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    // k % i = k - [k / i] * i
    i64 ans = n * k;
    i64 l = 1, r;
    while (l <= n) {
    	if (k / l == 0) break;
    	r = std::min(k / (k / l), n);
    	// 每个区间是等差数列
    	ans -= (k / l) * (r - l + 1) * (l + r) / 2;
    	l = r + 1;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
