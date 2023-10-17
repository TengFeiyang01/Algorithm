#include <bits/stdc++.h>
 
void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    for (auto&[r, l] : a) {
    	std::cin >> l >> r;
    }

    std::vector<int> f(n + 1);
    std::sort(a.begin(), a.end());

    // < x -> >= x - 1
    for (int i = 0; i < n; ++i) {
    	int j = std::lower_bound(a.begin(), a.begin() + i, std::make_pair(a[i].second - 1, 0x3f3f3f3f)) - a.begin();
    	f[i + 1] = std::max(f[i], f[j] + a[i].first - a[i].second + 1);
    }
    std::cout << f[n];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
