#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector a(2, std::vector<i64>(n));
    for (int i = 0; i < 2; ++i) {
    	for (int j = 0; j < n; ++j) {
	    	std::cin >> a[i][j];
    	}
    }
    std::vector<i64> f(3);

    for (int i = 1; i <= n; ++i) {
    	auto g = f;
    	f[0] = *std::max_element(g.begin(), g.end());
    	f[1] = std::max(g[0], g[2]) + a[0][i - 1];
    	f[2] = std::max(g[0], g[1]) + a[1][i - 1];
    }

    std::cout << *std::max_element(f.begin(), f.end());
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}