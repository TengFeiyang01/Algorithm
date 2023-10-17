#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
	int n = s.size();
	int ans = 0;
	for (int l = 0; l < n - 1; ++l) {
		std::string t = "01", f = "10";
		int x = 0, y = 0; 
		for (int r = l; r < n; ++r) {
			if (t[(r - l) % 2] != s[r]) {
				x += 1;
			}
			if (f[(r - l) % 2] != s[r]) {
				y += 1;
			}
			ans += std::min(x, y);
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