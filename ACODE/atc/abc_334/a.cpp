#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int a, b;
    std::cin >> a >> b;
    if (a > b) {
    	std::cout << "Bat\n";
    } else {
    	std::cout << "Glove\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
