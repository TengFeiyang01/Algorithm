#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n);
    for (auto &[l, r] : a) {
    	std::cin >> l >> r;
    }
    std::ranges::sort(a);

    int last = -inf, ans = 0;
    for (auto [l, r] : a) {
    	if (l > last) {
    		ans += r - l;
    		last = r - 1;
    	} else {
    		if (r - 1 > last) {
    			ans += r - last - 1;
                last = r - 1;
    		}
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
