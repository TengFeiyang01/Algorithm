#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	i64 n, x;
    std::cin >> n >> x;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::ranges::sort(a);
    bool f = 1;
    for (int i = 0; i < n; ++i) {
    	if (a[i] > x) {
    		if (f) {
    			x *= 2LL;
    			f = 0;
    		}
    	}
    	if (a[i] <= x) {
    		x += a[i] / 5;
    	} else {
    		break;
    	}
    }
    std::cout << x << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
