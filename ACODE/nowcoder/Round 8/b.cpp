#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n * 2);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i]; 
    }
    for (int i = n; i < n * 2; ++i) {
    	a[i] = a[i - n];
    }

    int x, y;
    std::cin >> x >> y;
    i64 ans = 0;
    --x, --y;
    if (x > y) {
    	std::swap(x, y);
    }
    i64 res = 0;
    
    for (int i = x; i < y; ++i) {
    	res += a[i];
    }
    
    for (int i = y; i < n + x; ++i) {
    	ans += a[i];
    }

    std::cout << std::min(ans, res);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
