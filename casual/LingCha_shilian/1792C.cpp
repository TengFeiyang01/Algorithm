#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int x = n >> 1, y = (n + 1) / 2 + 1;
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	if (a[i] == (n + 1) / 2) {
    		l = r = i;
    	}
    }

    int ans = n / 2;
    while (l >= 0 and r < n) {
    	while (l >= 0 and a[l] != x) --l;
    	if (l >= 0) x--;
    	else break;
    	while (r < n and a[r] != y) ++r;
    	if (r < n) y++;
    	else break;
    	ans--;
    }
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