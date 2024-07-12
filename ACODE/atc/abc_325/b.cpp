#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(24);
    int ans = 0;

    for (int i = 0; i < n; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	a[y % 24] += x;
    }
    for (int i = 0; i < 24; ++i) {
    	int s = 0;
    	for (int j = 0; j < 9; ++j) {
    		s += a[(i + j) % 24];
    	}
    	ans = std::max(ans, s);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}