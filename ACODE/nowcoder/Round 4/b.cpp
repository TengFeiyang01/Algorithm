#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	i64 n;
    std::cin >> n;
    if (n <= 3) {
    	std::cout << 0 << "\n";
    } else {
        std::cout << 2LL * ((n - 1LL) / 3) << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
