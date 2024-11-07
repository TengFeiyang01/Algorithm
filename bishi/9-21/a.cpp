#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0] >> a[i][1];
    }
    std::vector<int> pre(n), suf(n);
    std::vector<int> f;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
    	int y = a[i][1];
    	if (y > 0) continue;
    	if (f.empty() or f.back() <= y) {
    		f.push_back(y);
    		pre[i] = f.size();
    	} else {
    		auto it = std::lower_bound(f.begin(), f.end(), y);
    		*it = y;
    		pre[i] = it - f.begin();
    	}
    }
    f.clear();
    for (int i = n - 1; i >= 0; --i) {
    	int y = a[i][1];
    	if (y <= 0) continue;
    	if (f.empty() or f.back() >= y) {
    		f.push_back(y);
    		suf[i] = f.size();
    	} else {
    		auto it = std::lower_bound(f.begin(), f.end(), y);
    		*it = y;
    		suf[i] = it - f.begin();
    	}
    }
    int x = 0, ans = pre[0];
    for (int i = 0; i < n; ++i) {
    	ans = std::max(ans, x + suf[i]);
    	x = std::max(x, pre[i]);
    }
    ans = std::max(ans, x);
    std::cout << n - ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
