#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0, x; i < n; ++i) {
    	std::cin >> x;
        p[--x] = i;
    }
    
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += (p[i] < p[i - 1]);
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