#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), f(n + 1, inf);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    // f[i] 代表涂到第 i 个告示板时所需的最小的数目
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
    	int x = a[i - 1];
    	for (int j = i - 1; j >= 0; --j) {
    		if (j + x >= i and j + x <= n) {
    			f[j + x] = std::min(f[j + x], f[j] + 1);
    		}
    	}
    }
    if (f[n] == inf) f[n] = -1;
    std::cout << f[n] << "\n";
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
