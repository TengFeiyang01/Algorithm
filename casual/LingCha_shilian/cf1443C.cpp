#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<i64, 2>> a(n);
	i64 s = 0, ans = 0;    
	
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0];
    }
    
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][1];
    	s += a[i][1];
    }

    std::ranges::sort(a);
    ans = s;
    for (int i = 0; i < n; ++i) {
    	s -= a[i][1];
    	ans = std::min(ans, std::max(a[i][0], s));
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