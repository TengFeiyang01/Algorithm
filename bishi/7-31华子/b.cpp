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

    std::vector<int> f(n, 0);

    int ans = 0, mn = inf;
    for (int i = 0; i < n; ++i) {
    	int l = i - 1, r = i + 1;
    	while (l >= 0 and a[l][0] < a[i][0]) {
    		f[l] += a[i][1];
    		l--;
    	}
    	if (l >= 0) f[l] += a[i][1];
    	while (r < n and a[r][0] < a[i][0]) {
    		f[r] += a[i][1];
    		r++;
    	}
    	if (r < n) f[r] += a[i][1];
    }
    for (int i = 0; i < n; ++i) {
    	if (f[i] < f[ans]) {
    		ans = i;
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
