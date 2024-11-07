#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	a[i] ^= a[i - 1];
    }

    std::vector<int> l(q), r(q);
    for (int i = 0; i < q; ++i) {
    	std::cin >> l[i];
    }
    for (int i = 0; i < q; ++i) {
    	std::cin >> r[i];
    }
    int ans = 0, m;
    for (int i = 0; i < q; ++i) {
    	std::cin >> m;
    	int x = a[r[i]] ^ a[l[i] - 1];
    	i64 cur = 0, k = 0;
    	for (int j = 30; j >= 0; --j) {
    		int xb = (x >> j) & 1;
    		int kb = (m >> j) & 1;
    		if (xb == 0 and (k | (1 << j)) <= m) {
    			k |= 1 << j;
    			cur |= 1LL << j;
    		} else if (xb == 1) {
    			cur |= 1LL << j;
    		}
    	}
    	std::cout << cur << "\n";
    	ans ^= cur;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
