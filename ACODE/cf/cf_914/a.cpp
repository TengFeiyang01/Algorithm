#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int a, b;
    std::cin >> a >> b;
    std::vector<std::array<int, 2>> point(2);
    for (auto &[x, y] : point) std::cin >> x >> y;
    int ans = 0;
	std::set<std::pair<int, int>> p1, p2;
	std::vector<std::array<int, 2>> d{{a, b}, {a, -b}, {-a, b}, {-a, -b}, {b, a}, {b, -a}, {-b, -a}, {-b, a}};
	for (auto [dx, dy] : d) {
		p1.insert({point[0][0] + dx, point[0][1] + dy});
		p2.insert({point[1][0] + dx, point[1][1] + dy});
	}
	for (auto p : p1) {
		if (p2.count(p)) {
			ans++;
		}
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
