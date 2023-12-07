#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	int d = inf;
    	if (a[i] >= r) {
    		d = a[i] - r;
    	} else if (a[i] <= l) {
    		d = l - a[i];
    	} else {
    		d = 0;
    	}

    	int x1 = a[i] + d, x2 = a[i] - d;
    	if (l <= x1 and x1 <= r) {
    		std::cout << x1 << " ";
    	} else {
    		std::cout << x2 << " ";
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
