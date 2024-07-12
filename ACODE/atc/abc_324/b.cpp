#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 x;
    std::cin >> x;
    while (x % 3 == 0) {
    	x /= 3;
    }
    while (x % 2 == 0) {
    	x /= 2;
    }
    std::cout << (x == 1 ? "Yes\n" : "No\n");
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    solve();

    return 0;
}