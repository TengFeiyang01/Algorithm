#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    int f = 1;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
    	if (x >= a[i]) {
    		x += a[i] / 5;
    	} else if (f) {
    		f = 0;
    		x *= 2;
    		if (x >= a[i]) {
    			x += a[i] / 5;
    		}
    	}
    }
    if (!f) {
        x *= 2;
    }
    std::cout << x << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
