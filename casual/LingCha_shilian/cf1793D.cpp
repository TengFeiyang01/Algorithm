#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {


    int n, v;
    std::cin >> n;
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 0; i < n; ++i) {
    	std::cin >> v;
    	a[v] = i;
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> v;
    	b[v] = i;
    }

    i64 i = a[1], j = b[1];
    i64 l1 = i, r1 = i, l2 = j, r2 = j;
    if (i > j) {
    	std::swap(i, j);
    }
    i64 ans = i * (i + 1) / 2 + (j - i - 1) * (j - i) / 2 + (n - j - 1) * (n - j) / 2 + 1;
    for (int v = 2; v <= n; ++v) {
    	i = a[v];
    	j = b[v];
    	if (!(l1 < i && i < r1 || l2 < j && j < r2)) {
    		i64 l = -1;
    		if (i < l1) {
    			l = i;
    		}
    		if (j < l2) {
    			l = std::max(l, j);
    		}
    		i64 r = n;
    		if (i > r1) {
    			r = i;
    		}
    		if (j > r2) {
    			r = std::min(r, j);
    		}
    		ans += std::max(std::min(l1, l2) - l, 0ll) * std::max(r - std::max(r1, r2), 0ll);
    	}
    	l1 = std::min(l1, i);
    	r1 = std::max(r1, i);
    	l2 = std::min(l2, j);
    	r2 = std::max(r2, j);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
