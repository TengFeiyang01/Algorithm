#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(n), c(m);
    std::vector<std::vector<int>> need(n + 1), have(n + 1);

    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
        if (b[i] != a[i]) {
            need[b[i]].push_back(i);
        } else {
            have[b[i]].push_back(i);
        }
    }
    
    std::vector<int> ans(m);
    for (int i = 0; i < m; ++i) {
    	std::cin >> c[i];
    }

    for (int i = m - 1; i >= 0; --i) {
    	if (need[c[i]].size()) {
    		ans[i] = need[c[i]].back();
    		need[c[i]].pop_back();
    	} else if (have[c[i]].size()) {
    		ans[i] = have[c[i]].back();
    	} else {
    		if (i == m - 1) {
                std::cout << "NO\n";
                return;
    		} else {
    			ans[i] = ans.back();
    		}
    	}
    }
    for (int i = 1; i <= n; ++i) {
        if (need[i].size()) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
    for (auto x : ans) {
    	std::cout << x + 1 << " ";
    }
    std::cout << "\n";
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
