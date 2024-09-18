#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k, q;
    std::cin >> n >> k >> q;
    std::vector<int> a(k + 1), b(k + 1);

    for (int i = 1; i <= k; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 1; i <= k; ++i) {
    	std::cin >> b[i];
    }


    while (q--) {
    	int d;
    	std::cin >> d;
    	if (d == 0) {
    		std::cout << 0 << " \n"[q == 0];
    		continue;
    	}
    	int l = std::ranges::lower_bound(a, d) - a.begin();
    	std::cout << b[l - 1] + i64(b[l] - b[l - 1]) * (d - a[l - 1]) / (a[l] - a[l - 1]) << " \n"[q == 0];
    }

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
