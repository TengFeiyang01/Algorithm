#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	int a, b;
	std::cin >> a >> b;
	if (a < b) std::swap(a, b);
	if (a >= 2 * b) {
		std::cout << b << "\n";
	} else {
		std::cout << (a + b) / 3 << "\n";
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
