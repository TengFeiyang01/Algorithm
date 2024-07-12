#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int m;
	std::cin >> m;
	if (m % 2 or m & (m >> 1)) {
		std::cout << "-1\n";
	} else {
		int a = m >> 1, b = m;
		std::cout << (a | b) << " " << a << "\n";
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
