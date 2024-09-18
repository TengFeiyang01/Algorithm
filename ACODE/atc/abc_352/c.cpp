#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int mx = 0;
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	mx = std::max(mx, y - x);
    	ans += x;
    }
    std::cout << ans + mx << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
