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
    int ans = inf;
    int mx = std::ranges::max(a), mn = std::ranges::min(a);
    for (int i = mn; i <= mx; ++i) {
    	int res = 0;
    	for (auto x : a) {
    		res += (x - i) * (x - i);
    	}
    	ans = std::min(ans, res);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
