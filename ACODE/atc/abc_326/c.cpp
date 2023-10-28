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
    int ans = 0;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
    	int j = std::lower_bound(a.begin(), a.end(), a[i] + m) - a.begin();
    	ans = std::max(ans, j - i);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}