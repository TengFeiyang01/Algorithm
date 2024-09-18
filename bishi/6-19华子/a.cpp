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
    std::reverse(a.begin(), a.end());
    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
    	int x = 0;
    	while (a[i]) {
    		x *= 2;
    		if (a[i] & 1) {
    			x += 1;
    		}
    		a[i] >>= 1;
    	}
    	ans[i] = x;
    }
    
    for (int i = 0; i < ans.size(); ++i) {
    	std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
