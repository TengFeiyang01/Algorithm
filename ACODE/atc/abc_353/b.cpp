#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k, ans = 1;
    std::cin >> n >> k;
    std::vector<int> a(n);

    for (int i = 0, s = 0; i < n; ++i) {
    	std::cin >> a[i];
    	if (s + a[i] <= k) {
    		s += a[i];
    	} else {
    		s = a[i];
    		ans++;
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
