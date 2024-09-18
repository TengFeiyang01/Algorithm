#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, t0, pre = 0;
    std::cin >> n >> t0;
    
    bool ok = true;
    i64 L = t0, R = t0;
    for (int i = 0; i < n; ++i) {
    	i64 p, l, r;
    	std::cin >> p >> l >> r;
    	L -= p - pre;
    	R += p - pre;
    	if (R < l or L > r) {
    		ok = false;
    	}
    	L = std::max(L, l);
    	R = std::min(R, r);
    	pre = p;
    }
    std::cout << (ok ? "YES\n" : "NO\n");
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
