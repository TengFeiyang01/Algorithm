#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	s[i] = s[i - 1] + a[i];
    }
    a[0] = 0;
    while (q--) {
    	i64 x;
    	std::cin >> x;
    	i64 res = 0, l = 1;
    	i64 r = std::upper_bound(a.begin(), a.end(), x - a[l]) - a.begin();
    	while (l <= r) {
    		while (l < r and a[l] + a[r] > x) r--;
    		if (r + 1 <= n and (r - l + 1) % 2 == 0 and a[r + 1] <= x) r++;
    		std::cout << l << " " << r << "\n";
    		res += s[r] - s[l] - (a[l] * (r - l));
    		res %= 998244353;
    		l++;
    	} 
    	std::cout << "-=---------";
    	std::cout << res << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
