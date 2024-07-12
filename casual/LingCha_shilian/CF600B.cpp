#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::ranges::sort(a);
    for (int i = 0; i < m; ++i) {
    	int x;
    	std::cin >> x;
    	std::cout << std::ranges::upper_bound(a, x) - a.begin() << " \n"[i == m - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
