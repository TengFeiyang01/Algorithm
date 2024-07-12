#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::map<int, int> cnt;
    for (i64 i = 0; i < n; ++i) {
    	i64 x = a[i];
    	for (i64 j = 2; j * j <= x; ++j) {
    		while (x % j == 0) {
    			cnt[j]++;
    			x /= j;
    		}
    	}
    	if (x > 1) cnt[x]++;
    }
    for (auto [x, y] : cnt) {
    	if (y % n) {
    		std::cout << "NO\n";
    		return;
    	}
    }
    std::cout << "YES\n";
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