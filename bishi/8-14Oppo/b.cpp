#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    int x_or = 0, ans = 1;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int x : a) {
    	if ((x_or | x) <= k) {
    		x_or |= x;
    	} else {
    		x_or = x;
    		ans++;
    	}
    	if (x_or > k) {
    		std::cout << "-1\n";
    		return;
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
