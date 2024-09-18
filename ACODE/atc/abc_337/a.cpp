#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int a = 0, b = 0, x, y;
    while (n--) {
    	std::cin >> x >> y;
    	a += x;
    	b += y;
    }
    if (a > b) {
    	std::cout << "Takahashi";
    } else if (a == b) {
    	std::cout << "Draw";
    } else {
    	std::cout << "Aoki";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
