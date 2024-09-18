#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    i64 last = a[0] - k;
    for (int i = 1; i < n; ++i) {
    	i64 l = a[i] - k, r = a[i] + k;
    	if (r < last) {
    		std::cout << "No\n";
    		return;
    	} else {
    		last = std::max(last, l);
    	}
    }
    std::cout << "Yes\n";
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
