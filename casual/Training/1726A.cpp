#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    if (n == 1) {
    	std::cout << "0\n";
    	return;
    }
    int ans = 0;

    for (int i = n - 2; i >= 0; --i) {
    	ans = std::max(ans, a[i] - a[i + 1]);
    }
    for (int i = 0; i < n - 1; ++i) {
    	ans = std::max(ans, a[n - 1] - a[i]);
    }
    for (int i = 1; i < n; ++i) {
    	ans = std::max(ans, a[i] - a[0]);
    }
    std::cout << ans << "\n";
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
