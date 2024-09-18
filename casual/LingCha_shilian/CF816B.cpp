#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k, q;
    std::cin >> n >> k >> q;
    std::vector<int> a(200002), b(200002);
    for (int i = 0; i < n; ++i) {
    	int l, r;
    	std::cin >> l >> r;
    	a[l]++;
    	a[r + 1]--;
    }

    for (int i = 1; i <= 200000; ++i) {
    	a[i] += a[i - 1];
    	if (a[i] >= k) {
    		b[i]++;
    	}
    	b[i] += b[i - 1];
    }

    for (int i = 0, x; i < q; ++i) {
    	int l, r;
    	std::cin >> l >> r;
    	std::cout << b[r] - b[l - 1] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
