#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    i64 s1 = 0, s2 = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	s1 += a[i];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    	s2 += b[i];
    }
    std::cout << std::min(1LL * s2 + 1LL * n * std::ranges::min(a), 1LL * s1 + 1LL * n * std::ranges::min(b)) << "\n";
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