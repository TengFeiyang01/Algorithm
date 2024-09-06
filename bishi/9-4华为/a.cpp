#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) {
    	std::cin >> b[i];
    }
    m = std::min(m, n);
    for (int i = 0, k = 0; i < n; i += 1 << k, k++) {
    	std::map<int, int> tmp;
    	for (int j = i; j < i + (1 << k); ++j) {
   			tmp[a[j]]++;
    		if (j < m) {
    			tmp[b[j]]--;
    		}
    	}
    	for (auto t : tmp) {
    		int x = t.first, y = t.second;
    		if (y > 0) {
    			cnt[x] += y;
    		}
    	}
    }
    std::vector<std::pair<int, int>> ans;
    for (auto t : cnt) {
    	ans.push_back({-t.second, -t.first});
    }
    std::sort(ans.begin(), ans.end());
    for (auto t : ans) {
    	std::cout << -t.second;
    }
    if (ans.size() == 0) {
        std::cout << 0 << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
