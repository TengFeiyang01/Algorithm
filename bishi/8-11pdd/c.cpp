#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
	std::vector<int> s(n + 1);
	for (int i = 1; i <= n; ++i) {
		int x;
		std::cin >> x;
		if (x) {
			s[i] = s[i - 1] + 1;
		} else {
			s[i] = s[i - 1] - 1;
		}
	}    

	int p = 0, q = 0, a = 0, b = 0;
	for (int i = 1; i <= n; ++i) {
		a = std::max(a, s[i] - p);
		p = std::min(p, s[i]);
		b = std::min(b, s[i] - q);
		q = std::max(q, s[i]);
	}
	int x = s[n] - a * 2, y = s[n] - b * 2;
	int res = 0;
	if (x >= 0) {
		std::cout << (x - y) / 2 + 1;
	} else if (y <= 0) {
		std::cout << (x - y) / 2 + 1;
	} else {
		int z = std::max(abs(x), abs(y));
		if (y % 2) {
			std::cout << (z + 1) / 2;
		} else {
			std::cout << z / 2 + 1 << "\n";
		}
	}

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
