#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int j = 0; j < n; ++j) {
    	std::cin >> b[j];
    }
    int ans = 1;
    for (int l = 0, r = 1; r < n; r++) {
    	while (r < n and a[r] - a[r - 1] == b[r] - b[r - 1]) {
    		r++;
    	}
    	ans = std::max(ans, r - l);
    	l = r;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
