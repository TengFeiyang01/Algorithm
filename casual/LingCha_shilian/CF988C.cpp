#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::map<int, std::pair<int, int>> mp;
    for (int j = 0; j < n; ++j) {
    	int m, s = 0;
    	std::cin >> m;
    	std::vector<int> a(m);
    	for (int i = 0; i < m; ++i) {
    		std::cin >> a[i];
    		s += a[i];
    	}
    	for (int i = 0; i < m; ++i) {
    		if (mp.count(s - a[i])) {
    			auto [x, y] = mp[s - a[i]];
    			std::cout << "YES\n";
    			std::cout << x << " " << y << "\n";
    			std::cout << j + 1 << " " << i + 1 << "\n";
    			return;
    		}
    	}
    	for (int i = 0; i < m; ++i) {
	    	mp[s - a[i]] = {j + 1, i + 1};
    	}
    }
    std::cout << "NO\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
	