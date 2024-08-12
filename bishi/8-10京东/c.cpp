#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	int x = a[i];
    	a[i] = 0;
    	while (x) {
    		if (x & 1) {
    			a[i]++;
	    		x--;
    		}
    		if (x) {
	    		a[i]++;
	    		x >>= 1;
    		}
    	}
    }
    int p = 0, q = 0;
    for (int i = n; i > 0; i--) {
    	a[i] -= a[i - 1];
    	if (a[i] > 0) {
    		p += a[i];
    	} else {
    		q -= a[i];
    	}
    }
    std::cout << std::max(p, q) << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
