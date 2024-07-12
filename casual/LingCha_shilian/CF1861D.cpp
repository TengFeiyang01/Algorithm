#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<int> suf(n);
    for (int i = n - 2; i >= 0; --i) {
    	suf[i] = suf[i + 1];
    	if (a[i] >= a[i + 1]) {
    		suf[i]++;
    	}
    }
    int pre = 1, ans = suf[0];
    for (int i = 1; i < n; ++i) {
    	ans = std::min(ans, pre + suf[i]);
    	if (a[i] >= a[i - 1]) {
    		pre++;
    	}
    }
    ans = std::min(ans, pre);
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
