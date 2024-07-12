#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int l = 0, r = 0;
    std::map<int, int> last;
    int ans = 0;
    std::vector<std::pair<int, int>> res;
    std::vector<int> a(n);
    for (int r = 0; r < n; ++r) {
    	std::cin >> a[r];
    	if (last[a[r]]) {
    		res.emplace_back(l + 1, r + 1);
    		while (l <= r) {
    			last[a[l]] = 0;
    			l++;
    		}
    	} else {
	    	last[a[r]] = r + 1;
    	}
    }
    if (res.size() == 0) {
        std::cout << "-1\n";
        return;
    }
    std::cout << res.size() << "\n";
    if (res.back().second != n) res.back().second = n;
    for (auto [x, y] : res) {
    	std::cout << x << " " << y << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
