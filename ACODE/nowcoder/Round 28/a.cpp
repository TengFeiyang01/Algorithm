#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int s = 0;
    for (int i = 0; i < 6; ++i) {
    	int x;
    	std::cin >> x;
    	s += x;
    }
    std::cout << s << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
        solve();

    return 0;
}
