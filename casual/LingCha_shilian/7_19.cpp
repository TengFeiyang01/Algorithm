#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n);
    i64 ans = n;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	ans += a[i];
    }
    std::sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    while (l < r) {
    	if (a[l] + a[r] <= m) {
    		l += 1;
    		if (l < r) {
    			ans -= 2;
    		} else {
    			ans -= 1;
    		}
    	}
    	r -= 1;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
