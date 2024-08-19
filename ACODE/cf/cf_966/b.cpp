#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    bool ok = true;
    for (int i = 0, x; i < n; ++i) {
    	std::cin >> x;
    	--x;
    	if (i == 0) {
    		a[x]++;
    	} else {
    		if (!(x and a[x - 1] or x + 1 < n and a[x + 1])) {
    			ok = false;
    		} else {
    			a[x] = 1;
    		}
    	}
    }
    if (ok) {
    	std::cout << "Yes\n";
    } else {
    	std::cout << "No\n";
    }
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
