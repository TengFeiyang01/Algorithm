#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b); 
}

i64 lcm(int a, int b) {
    return 1LL * a * b / gcd(a, b);
}

void solve() {
	int a, b;
	std::cin >> a >> b;
	std::cout << gcd(a, b) << " " << lcm(a, b) << "\n";
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
