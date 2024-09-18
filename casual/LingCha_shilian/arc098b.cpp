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
    int l = 0, s = 0, x = 0;
    for (int r = 0; r < n; ++r) {
    	s += a[r];
    	x ^= a[r];
    	while (s > x) {
    		s -= a[l];
    		x ^= a[l];
    		l += 1;
    	}
    	ans += r - l + 1;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}