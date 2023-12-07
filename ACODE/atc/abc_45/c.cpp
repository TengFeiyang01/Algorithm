#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;
	int n = s.size();
	i64 ans = 0;

	std::function<void(int, i64, i64)> dfs = [&](int i, i64 sum, i64 t) {
		if (i == n - 1) {
			ans += (sum + t);
			return;
		}
		dfs(i + 1, sum, 10 * t + (s[i + 1] - '0'));
		dfs(i + 1, sum + t, s[i + 1] - '0');
	};
	dfs(0, 0, s[0] - '0');
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
