#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    int y = 0;
    for (int i = 0; i < m; ++i) {
    	std::cin >> b[i];
        y |= b[i];
    }
    int mn = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        mn ^= a[i];
        mx ^= (a[i] | y);
    }
    if (mn > mx) {
        std::swap(mx, mn);
    }

    std::cout << mn << " " << mx << "\n";
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