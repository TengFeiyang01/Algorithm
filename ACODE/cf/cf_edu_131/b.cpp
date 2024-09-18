#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m, x, y, d;
    std::cin >> n >> m >> x >> y >> d;
    if ((x - 1 <= d or m - y <= d) and (y - 1 <= d or n - x <= d)) {
    	std::cout << "-1\n";
    } else {
    	std::cout << n + m - 2 << "\n";
    }
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
