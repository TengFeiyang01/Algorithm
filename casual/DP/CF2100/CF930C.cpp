#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m + 2);
    for (int i = 0; i < n; ++i) {
    	int l, r;
    	std::cin >> l >> r;
    	a[l]++;
    	a[r + 1]--;
    }
    std::vector<int> pre(m + 1), suf(m + 1);
    for (int i = 1; i <= m; ++i) a[i] += a[i - 1];

    std::vector<int> f;
	int len;
    for (int i = 1; i <= m; ++i) {
    	if (f.empty() || f.back() <= a[i]) {
    		f.push_back(a[i]);
    		pre[i] = f.size();
    	} else {
    		len = std::ranges::upper_bound(f, a[i]) - f.begin();
    		f[len] = a[i];
	    	pre[i] = len + 1;
    	}
    }
    f.clear();
    
    for (int i = m; i >= 1; --i) {
    	if (f.empty() || f.back() <= a[i]) {
    		f.push_back(a[i]);
    		suf[i] = f.size();
    	} else {
    		len = std::ranges::upper_bound(f, a[i]) - f.begin();
    		f[len] = a[i];
	    	suf[i] = len + 1;
    	}
    }
    int ans = 0;

    for (int i = 1; i <= m; ++i) {
    	ans = std::max(ans, pre[i] + suf[i] - 1);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
