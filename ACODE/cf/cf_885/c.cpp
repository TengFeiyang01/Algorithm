#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    auto calc = [&](int x, int y) {
    	if (x == 0 and y == 0) return 0;
    	int g = std::__gcd(x, y);
    	x /= g;
    	y /= g;
    	if (x % 2 == 0) return 1;
    	if (y % 2 == 0) return 2;
    	return 4;
    };


    int ans = 0;
    for (int j = 0; j < n; ++j) {
    	std::cin >> b[j];
    	ans |= calc(a[j], b[j]);
    }
    int s = __builtin_popcount(ans);
    std::cout << (s <= 1 ? "YES\n" : "NO\n");
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
