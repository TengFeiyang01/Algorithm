#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m, k, h;
    std::cin >> n >> m >> k >> h;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	int d = abs(x - h);
        if (d == 0) continue;
    	if (d % k or d / k > (m - 1)) continue;
    	ans++; 
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
