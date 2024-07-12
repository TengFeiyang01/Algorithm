#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 1);
    i64 ans = 0;
    for (int p = n - 1; p >= 0; --p) {
    	auto b = a;
    	std::reverse(b.begin() + p, b.end());
    	i64 res = 0, mx = 0;
    	for (int i = 0; i < n; ++i) {
    		res += 1LL * (i + 1) * b[i];
    		mx = std::max(mx, 1LL * (i + 1) * b[i]);
    	}
    	ans = std::max(ans, res - mx);
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
