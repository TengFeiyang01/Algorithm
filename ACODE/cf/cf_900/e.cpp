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
    std::vector b(31, std::vector<int>(n + 2));
    for (int i = 0; i < 31; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		b[i][j] += b[i][j - 1];
            if (a[j - 1] >> i & 1) {
    			b[i][j]++;
    		}
    	}
    }
    int q, l, r, k;

    std::cin >> q;
    auto check = [&](int st, int ed) {
    	int ans = 0;
    	for (int i = 0; i < 31; ++i) {
    		if (b[i][ed] - b[i][st - 1] == ed - st + 1) {
    			ans |= 1ll << i;
    		}
    	}
    	return ans >= k;
    };

    while (q--) {
    	std::cin >> l >> k;
    	int x = l;
        int r = n + 1;
        if (a[l - 1] < k) {
            std::cout << "-1 ";
            continue;
        }
    	while (l < r) {
    		int mid = l + r + 1 >> 1;
    		if (check(x, mid)) {
    			l = mid;
    		} else {
    			r = mid - 1;
    		}
    	}
    	std::cout << l << " ";
    }
    std::cout << "\n";
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