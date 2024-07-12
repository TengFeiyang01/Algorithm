#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    i64 i = 0, pre = -1e17, ans = 0;
    for (int j = 0, v; j < m; ++j) {
    	std::cin >> v;
    	while (i < n and a[i] <= v) {
    		ans = std::max(ans, std::min(a[i] - pre, v - a[i]));
    		i++;
    	}
    	pre = v;
    }
    if (i < n) {
    	ans = std::max(ans, a[n - 1] - pre);
    }
    std::cout << ans << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
