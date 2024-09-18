#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::string s;
	std::cin >> s;
	int cnt = std::ranges::count(s, 'B');
	if (cnt == k) {
		std::cout << "0\n";
	} else if (cnt > k) {
		int need = cnt - k;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'B') {
				if (--need == 0) {
					std::cout << "1\n" << i + 1 << " " << "A" << "\n";
					return;
				}
			}
		}
	} else {
		int need = k - cnt;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'A') {
				if (--need == 0) {
					std::cout << "1\n" << i + 1 << " " << "B\n";
					return;
				}
			}

		}
	}
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
