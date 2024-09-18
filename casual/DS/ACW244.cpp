#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n, q;
	std::cin >> n >> q;
	std::vector<i64> a(n + 1), d1(n + 1), d2(n + 1);
	
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	for (int i = n; i > 1; --i) {
		a[i] -= a[i - 1];
	}

	auto add = [&](std::vector<i64> &tr, int x, i64 val) {
		for (int i = x; i <= n; i += i & -i) {
			tr[i] += val;
		}
	};

	auto query = [&](std::vector<i64> &tr, int x) {
		i64 res = 0;
		while (x) {
			res += tr[x];
			x -= x & -x;
		}
		return res;
	};

	for (int i = 1; i <= n; ++i) {
		add(d1, i, a[i]);
		add(d2, i, i64(i - 1) * a[i]);
	}

	while (q--) {
		char op;
		i64 l, r, d;
		std::cin >> op;
		if (op == 'Q') {
			std::cin >> l >> r;
			std::cout << r * query(d1, r) - (l - 1) * query(d1, l - 1) - query(d2, r) + query(d2, l - 1) << "\n";
		} else {
			std::cin >> l >> r >> d;
			add(d1, l, d);
			if (r + 1 <= n) add(d1, r + 1, -d);
			add(d2, l, d * (l - 1));
			if (r + 1 <= n) add(d2, r + 1, -d * r);
		}
	}
    
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
