#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q, mod;
    std::cin >> n >> q >> mod;
    std::vector<i64> f(n + 2), a(n + 1);
    std::cin >> a[1];
    f[1] = 1;

    for (int i = 2; i <= n; ++i) {
    	std::cin >> a[i];
    	f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
    for (int i = 1; i <= n; ++i) {
    	i64 v;
    	std::cin >> v;
    	a[i] = (a[i] - v) % mod;
    }

    int cnt = 0;

    for (int i = n; i > 1; --i) {
    	a[i] = (a[i] - a[i - 1] - a[i - 2]) % mod;
    	if (a[i] == 0) {
    		cnt++;
    	}
    }
    cnt += a[1] == 0;

    auto update = [&](int i, int add) {
    	if (i > n) return;
    	if (a[i] == 0) cnt--;
    	a[i] = (a[i] + add) % mod;
    	if (a[i] == 0) cnt++;
    };

    while (q--) {
    	char op;
    	int l, r;
    	std::cin >> op >> l >> r;
    	int sgn = (op & 1) * 2 - 1;
    	update(l, sgn);
    	update(r+1, -f[r-l+2]*sgn);
    	update(r+2, -f[r-l+1]*sgn);
    	if (cnt == n) {
    		std::cout << "YES\n";
    	} else {
    		std::cout << "NO\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
