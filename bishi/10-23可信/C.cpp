#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	std::string rk;
	int sc[26]{0};
	std::cin >> rk;
	for (int i = 0; i < 26; ++i) {
		sc[rk[i] - 'a'] = i;
	}

	int n;
	std::cin >> n;
	std::vector<std::string> s(n);
	for (auto &c : s) {
		std::cin >> c;
	}
	std::sort(s.begin(), s.end(), [&](auto x, auto y) {
		for (int p = 0; p < std::min(x.size(), y.size()); ++p) {
			if (sc[x[p] - 'a'] != sc[y[p] - 'a']) {
				return sc[x[p] - 'a'] < sc[y[p] - 'a'];
			}
		}
		return x.size() < y.size();
	});
	for (auto &c : s) {
		std::cout << c << "\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
