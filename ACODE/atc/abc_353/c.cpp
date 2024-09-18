#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<i64> a(n);
	i64 ans = 0, N = 100000000, tot = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		tot += a[i];
	}
	std::ranges::sort(a);


	for (int i = 0; i < n; ++i) {
		int j = std::ranges::lower_bound(a, N - a[i]) - a.begin();
		if (j <= i) j = i + 1;
		tot -= a[i];
		ans += i64(n - i - 1) * a[i] + tot - (n - j) * N; 
	}

	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
