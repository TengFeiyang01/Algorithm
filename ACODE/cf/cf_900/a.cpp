#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    int ok = 0;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	if (x == k) {
    		ok = 1;
    	}
    }
    std::cout << (ok ? "YES\n" : "NO\n");
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