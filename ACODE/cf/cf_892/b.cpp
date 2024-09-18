#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> b;
    i64 sum = 0, ans = 0;
    int mn = inf;
    for (int i = 0; i < n; ++i) {
    	int x, fi = inf, se = inf;
    	std::cin >> x;
    	for (int j = 0; j < x; ++j) {
    		int y;
    		std::cin >> y;
    		if (y <= fi) {
    			se = fi;
    			fi = y;
    		} else if (y < se) {
    			se = y;
    		}
            mn = std::min(mn, y);
    	}
    	b.push_back({fi, se});
    	sum += se;
    }

    for (int i = 0; i < n; ++i) {
    	ans = std::max(ans, sum + mn - b[i][1]);
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
