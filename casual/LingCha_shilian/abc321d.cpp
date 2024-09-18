#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, p;
    std::cin >> n >> m >> p;
    std::vector<i64> a(n), b(m);
    i64 ans = 0, tot = 0;


    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    
    for (int i = 0; i < m; ++i) {
    	std::cin >> b[i];
    	tot += b[i];
    }

    std::ranges::sort(a);
    std::ranges::sort(b);
    
    int i = 0, j = m - 1;
    while (i < n) {
    	while (j >= 0 && a[i] + b[j] >= p) {
    		tot -= b[j--];
    	}
    	ans += i64(j + 1) * a[i] + tot + i64(m - 1 - j) * p;
    	i++;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}	