#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(3);
    a[k - 1] = 1;
    for (int i = 0; i < n; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	--x, --y;
    	std::swap(a[x], a[y]);
    }
    for (int i = 1; i <= 3; ++i) {
    	if (a[i - 1]) {
    		std::cout << i << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
