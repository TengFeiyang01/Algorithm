#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, d;
    std::cin >> n >> d;
    std::vector<int> a(n);
    for (auto &x : a) {
    	std::cin >> x;
    }
    std::ranges::sort(a);
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
    	int j = std::ranges::upper_bound(a, a[i] + d) - a.begin() - 1;
    	i64 x = j - i;
    	ans += x * (x - 1) / 2;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
