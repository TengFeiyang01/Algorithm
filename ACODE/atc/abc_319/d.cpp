#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    auto check = [&](i64 k) {
    	i64 tot = 1, s = a[0];
        for (int i = 1; i < n; ++i) {
            if (s + 1 + a[i] > k) {
                s = a[i];
                tot++;
            } else {
                s += a[i] + 1;
            }
        }
    	return tot <= m;
    };

    i64 l = std::ranges::max(a), r = std::accumulate(a.begin(), a.end(), 0LL) + n - 1;

    while (l < r) {
    	i64 mid = l + r >> 1;
    	if (check(mid)) {
    		r = mid;
    	} else {
    		l = mid + 1;
    	}
    }
    std::cout << l << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}