#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;
	int ans = -1;
	auto check = [&](int x) {
		if (x < 2) return 0;
		for (int i = 2; i * i <= x; ++i) {
			if (x % i == 0) {
				return 0;
			}
		}
		return 1;
	};
	std::sort(s.begin(), s.end());
	do {
		if (s[0] == '0') continue;
		int x = std::stoi(s);
		if (check(x)) {
			ans = x;
		}

	} while (std::next_permutation(s.begin(), s.end()));
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
