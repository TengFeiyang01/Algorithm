#include <bits/stdc++.h>

constexpr int mx = 1.1e4;

void solve() {
	int n, m, r;
	std::cin >> n >> m >> r;
	
	std::vector st(n + 1, std::vector(m + 1, std::bitset<mx>()));
	for (auto &a : st)
		for (auto &v : a) v.set();

	for (int i = 0; i < r; ++i) {
		int t, op, x;
		std::cin >> t >> op >> x;
		if (t >= mx) continue;
		if (op == 1) {
			for (int i = 0; i <= m; ++i) st[x][i][t] = false;
		} else {
			for (int i = 0; i <= n; ++i) st[i][x][t] = false;
		}
	}
	std::queue<std::array<int, 3>> q;
	

	auto push = [&](int x, int y, int t) {
		if (t >= mx) return;
		if (!st[x][y][t]) return;
		q.push({x, y, t});
		st[x][y][t] = false;
	};

	q.push({0, 0, 0});
	while (q.size()) {
		auto [x, y, t] = q.front();

		if (x == n and y == m) {
			std::cout << t << "\n";
			return;
		}
		
		q.pop();
		push(x, y, t + 1);
		if (x < n) push(x + 1, y, t + 1);
		if (y < m) push(x, y + 1, t + 1);
	}
	std::cout << -1 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
