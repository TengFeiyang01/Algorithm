#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    std::vector<int> a, b;
    int n = s.size(), m = t.size();
    for (int i = 1; i < 1 << n; ++i) {
    	int now = 0;
    	for (int j = 0; j < n; ++j) {
    		if (i >> j & 1) {
    			now = now * 10 + (s[j] - '0');
    		}
    	}
    	a.push_back(now);
    }
    for (int i = 1; i < 1 << m; ++i) {
    	int now = 0;
    	for (int j = 0; j < m; ++j) {
    		if (i >> j & 1) {
    			now = now * 10 + (t[j] - '0');
    		}
    	}
    	b.push_back(now);
    }
    
    int ans = inf;
    for (int x : a) {
    	for (int y : b) {
    		int v1 = n - std::to_string(x).size(), v2 = m - std::to_string(y).size();
    		if (x % y == 0 or y % x == 0) {
    			ans = std::min(ans, v1 + v2);
    		}
    	}
    }
    if (ans == inf) ans = -1;
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
