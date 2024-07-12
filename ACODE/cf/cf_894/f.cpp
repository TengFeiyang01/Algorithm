#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 w, f, n, s = 0;
    std::cin >> w >> f >> n;
    std::vector<int> a(n);
    std::bitset<1000010> b;
    b[0] = 1;
    
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	s += a[i];
    	b |= (b << a[i]);  // 这个可以得出所有能够凑出来的方案的和
    }	


    i64 ans = inf;
    for (int i = 0; i <= s; ++i) {
    	if (b[i]) {
    		ans = std::min(ans, std::max((i + w - 1) / w, (s - i + f - 1) / f));
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