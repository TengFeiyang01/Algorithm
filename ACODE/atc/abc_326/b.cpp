#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    for (int i = n; i <= 999; ++i) {
    	if ((i % 100 / 10) * (i / 100) == (i % 10)) {
    		std::cout << i << "\n";
    		return;
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}