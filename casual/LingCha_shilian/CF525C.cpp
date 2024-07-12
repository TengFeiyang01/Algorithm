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
    i64 ans = 0;
    std::ranges::sort(a);
    std::ranges::reverse(a);
    for (int i = -1; i < n; ) {
    	for (i += 2; i < n && a[i - 1] - a[i] > 1; i++) {}
    	if (i >= n) break;
    	i64 v = a[i];
    	for (i += 2; i < n and a[i - 1] - a[i] > 1; i++) {}
    	if (i >= n) break;
    	int w = a[i];
    	ans += v * w;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
