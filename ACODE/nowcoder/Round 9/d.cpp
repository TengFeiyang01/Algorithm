#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    i64 s = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	s += a[i];
    }

    std::ranges::sort(a);
 
    if (s % n == 0) {
    	i64 x = s / n, ans = 0;
    	for (int i = 0; i < n; ++i) {
    		ans += abs(a[i] - x);
    	}
    	std::cout << ans / 2;
    } else {
        auto dfs = [&](int l, int r, i64 s) ->i64 {
            
            i64 x = s / (n - 1), y = x + 1;

            i64 c = 0, d = 0, e = 0, f = 0;
            
            for (int i = l; i <= r; ++i) {
                if (a[i] >= x) c += a[i] - x;
                else d += x - a[i];
                if (a[i] >= y) e += a[i] - y;
                else f += y - a[i];
            }
            return std::min(std::max(c, d), std::max(e, f));
        };
        std::cout << std::min(dfs(0, n - 2, s - a[n - 1]), dfs(1, n - 1, s - a[0]));
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
