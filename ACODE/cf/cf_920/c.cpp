#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, f, a, b;
    std::cin >> n >> f >> a >> b;
    std::vector<i64> m(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> m[i];
    }
    for (int i = 1; i <= n; ++i) {
    	i64 y = (m[i] - m[i - 1]) * a;
    	i64 x = b;
    	if (x <= y) {
    		f -= x;
    	} else {
    		f -= y;
    	}
    }
    if (f > 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
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
