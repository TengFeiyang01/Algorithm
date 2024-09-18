#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n;
    std::cin >> n;
    i64 p = 2 * n - 1;
    std::cout << (p + 1) * n << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
	solve();

    return 0;
}