#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    //O(n^2)
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
    	int mx = a[i], sum = 0;
    	std::vector<std::pair<int, int>> stk;
    	for (int j = i; j < n; ++j) {
    		int cur = 0;
    		while (stk.size() and stk.back().first > a[j]) {
    			cur += stk.back().second + 1;
    			sum -= stk.back().second;
    			stk.pop_back();
    		}
    		sum += cur;
    		mx = std::max(mx, a[j]);
    		stk.push_back({mx, cur});
    		ans += sum;
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
