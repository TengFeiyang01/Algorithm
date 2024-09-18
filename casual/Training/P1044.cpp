#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    i64 x = 1;
    for (int i = 2; i <= n; ++i) {
    	x = x * (4 * n - 2) / (n + 1);
    }
    std::cout << x << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
