#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n, m = 0;
	std::cin >> n;
	std::vector<std::string> S(n);
	for (auto &s : S) {
		std::cin >> s;
		m = std::max(m, int(s.size()));
	}
	std::reverse(S.begin(), S.end());
	for (int i = 0; i < m; ++i) {
		std::string t;
		for (auto s : S) {
			if (int(s.size()) >= i + 1) {
				t += s[i];
			} else {
				t += "*";
			}
		}
		while (t.back() == '*') {
			t.pop_back();
		}
		std::cout << t << "\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
