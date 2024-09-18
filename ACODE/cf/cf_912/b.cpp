#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector a(n, std::vector<int>(n));
    std::vector<int> ans(n, (1LL << 30) - 1);
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		std::cin >> a[i][j];
    	}
    	for (int j = 0; j < n; ++j) {
    		if (i != j) {
    			ans[i] &= a[i][j];
    		}
    	}
    }
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		if (i != j and ((ans[i] | ans[j]) != a[i][j])) {
    			std::cout << "NO\n";
    			return;
    		}
    	}
    }
    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) {
    	std::cout << ans[i] << " \n"[i == n - 1];
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
