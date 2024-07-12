#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n / 2; i++) {
    	std::cout << i * 2 << " ";
    }
    for (int i = 1; i <= n - n / 2; i++) {
    	std::cout << i * 2 - 1 << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
