#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> m >> n;
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0] >> a[i][1];
    }
    std::function<bool(int, int)> f = [&](int x, int y) {
    	for (auto [px, py] : a) {
    		if (px == x or px == y or py == y or py == x) {
    			continue;
    		}
    		if (y > 0) return false;
    		return f(x, px) or f(x, py);
    	}
    	return true;
    };
    if (f(a[0][0], 0) or f(a[0][1], 0)) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
