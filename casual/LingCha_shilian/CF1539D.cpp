#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<i64, 2>> a(n);
    i64 need = 0;
    for (auto &[x, y] : a) {
    	std::cin >> x >> y;
    	need += x;
    }
    std::ranges::sort(a, [&](auto &x, auto &y){ return x[1] < y[1]; });
    int l = 0, r = n - 1;
    i64 ans = 0, now = 0;

    while (now != need) {
    	if (now >= a[l][1]) {
    		now += a[l][0];
    		ans += a[l][0];
    		++l;
    	} else if (now + a[r][0] >= a[l][1]) {
    		a[r][0] -= a[l][1] - now;
    		ans += 2 * (a[l][1] - now);
    		now = a[l][1];
    	} else {
    		now += a[r][0];
    		ans += a[r][0] * 2;
    		r--;
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
