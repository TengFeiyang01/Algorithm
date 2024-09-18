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
    	cnt[a[i]]++;
    }
	
    int ans = 0;
    if (n == 1) {
    	std::cout << a[0] / 2 << "\n";
    	return;
    }

    for (int i = 0; i < n; ++i) {
    	int x = cnt.count(a[i] * 2) || cnt.count(a[i] * 2 + 1);
    	
    	if ((cnt[a[i]] + x) * 2 >= n) {
    		ans = std::max(ans, a[i]);
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
