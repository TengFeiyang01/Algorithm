#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::multiset<int>> left(3), right(3);
    std::vector<std::array<int, 3>> a(n);
    for (int j = 0; j < 3; ++j) {
    	for (int i = 0; i < n; ++i) {
    		std::cin >> a[i][j];
    		if (i) {
    			right[j].insert(a[i][j]);
    		}
    	}
    }

    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
    	for (int j = 0; j < 3; ++j) {
    		left[j].insert(a[i - 1][j]);
    		right[j].erase(right[j].find(a[i][j]));
    	}
    	for (int x : {0, 1, 2}) {
    		for (int y : {0, 1, 2}) {
    			for (int z : {0, 1, 2}) {
    				if (x != y and y != z and x != z) {
    					ans = std::max(ans, a[i][y] + *left[x].rbegin() + *right[z].rbegin());
    				}
    			}
    		}
    	}
    }
    std::cout << ans << "\n";
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
