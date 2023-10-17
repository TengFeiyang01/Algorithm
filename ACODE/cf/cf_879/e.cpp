#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<i64> a(n);
	for (auto &x : a) std::cin >> x;
	//子数组 lcm 模板题 
	i64 inf = 24 * n;
	std::set<i64> s, f;
	for (auto x: a) {
		std::set<i64> g;
		for (i64 y : f) {
			i64 m = std::lcm(y, x);
			if (m < inf) {
				g.insert(m);
				s.insert(m);
			}
		}
		g.insert(x);
		s.insert(x);
		f = g;
	}
	int x = 1;
	while (s.count(x)) {
		x++;
	}
	std::cout << x << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
