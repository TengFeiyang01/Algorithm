#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 25);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    }
    
    std::vector<i64> dp(n + 25);

    for (int i = 24; i <= n + 24; i += 24) {
	    std::vector<int> p{1, 2, 3, 4};
    	do {
    		int j = i - 24;
    		i64 pre = dp[j];
    		i64 s = 0, f = 1;
    		for (int x : p) {
    			s += x;
    			pre += a[j + s];
    			if (pre < 0) {
    				f = 0;
    				break;
    			}
    			dp[j + s] = std::max(dp[j + s], pre);
    		}
    		if (f) {
	    		dp[i] = std::max(dp[i], pre);
    		}
    	} while (std::next_permutation(p.begin(), p.end()));
    }
    std::cout << dp[n] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
