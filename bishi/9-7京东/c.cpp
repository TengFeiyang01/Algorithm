#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, l, b;
    std::cin >> n >> l >> m >> b;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    int pre = 0, cnt = 0;

    int k = 0, st = 0;
    while (st <= l) {
    	if (k < n) {
    		i64 dist = a[k] - st;
    		st = a[k];
    		pre += dist / b;

    		while (k < n and a[k] - st < b) {
    			k++;
    		}
    		cnt++;
    		st += b;
    	} else {
    		pre += (l - st) / b;
    		st = l + 1;
    	}
    }
    if (cnt <= m && cnt + pre >= m) {
    	std::cout << "Yes\n";
    } else {
    	std::cout << "No\n";
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
