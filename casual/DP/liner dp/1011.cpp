#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), pre(n, 1), suf(n, 1);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < i; ++j) {
    		if (a[i] > a[j]) {
    			pre[i] = std::max(pre[i], pre[j] + 1);
    		}
    	}
    }
    for (int i = n - 1; i >= 0; --i) {
    	for (int j = n - 1; j > i; --j) {
    		if (a[i] > a[j]) {
    			suf[i] = std::max(suf[i], suf[j] + 1);
    		}
    	}
    }
    int ans = inf;
    for (int i = 0; i < n; ++i) {
    	ans = std::min(ans, n - pre[i] - suf[i] + 1);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
