#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
    	int x;
    	std::cin >> x;
    	if (a + x >= b) {
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