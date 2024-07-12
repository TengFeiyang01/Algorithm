#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n;
    std::vector<int> d(n);
    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	d[u]++, d[v]++;
    }
    std::cout << (std::ranges::count(d, 1) + 1) / 2 << "\n";
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
