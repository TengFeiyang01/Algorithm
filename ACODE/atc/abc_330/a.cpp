#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, x, ans = 0;
    std::cin >> n >> x;
    for (int i = 0; i < n; ++i) {
    	int a;
    	std::cin >> a;
    	ans += a >= x;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
