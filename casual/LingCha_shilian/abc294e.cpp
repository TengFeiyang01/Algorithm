#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	i64 L;
    int n, m;
    std::cin >> L >> n >> m;
    std::vector<std::array<i64, 2>> a(n), b(m);
    for (auto &[x, y] : a) std::cin >> x >> y;
    for (auto &[x, y] : b) std::cin >> x >> y;

    int i = 0, j = 0;
	i64 ans = 0;
	while (i < n and j < m) {
		if (a[i][0] == b[j][0]) {
			ans += std::min(a[i][1], b[j][1]);
		} 
		if (a[i][1] > b[j][1]) {
			a[i][1] -= b[j][1];
			j += 1;
		} else {
			b[j][1] -= a[i][1];
			i += 1;
		}
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}