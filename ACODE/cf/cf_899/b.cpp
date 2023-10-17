#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::map<int, std::vector<int>> pos;
    std::map<int, int> cnt;

    std::vector a(n, std::vector<int>());

    int tot = 0;

    for (int i = 0; i < n; ++i) {
    	int len, x;
    	std::cin >> len;
    	a[i].resize(len);
    	for (int j = 0; j < len; ++j) {
    		std::cin >> a[i][j];
    		pos[a[i][j]].emplace_back(i);
    		if (++cnt[a[i][j]] == 1) {
    			tot++;
    		}
    	}
    }
    int ans = 0;
    for (int val = 1; val <= 50; ++val) {
    	if (pos[val].empty()) continue;
    	int cur = tot;
    	
    	for (auto &v : pos[val]) {
    		for (auto x : a[v]) {
    			if (--cnt[x] == 0) {
    				--cur;
    			}
    		}
    	}
        
    	if (cur < tot) {
    		ans = std::max(ans, cur);
    	}
    	for (auto &v : pos[val]) {
    		for (auto x : a[v]) {
    			++cnt[x];
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