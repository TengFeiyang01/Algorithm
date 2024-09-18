#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int m, d, t;
	std::cin >> m >> d >> t;
	int cur = 0, ans = 0;
	while (cur < d and ans < t) {
		if (m >= 10) {
			cur += 60;
			m -= 10;
		} else {
			cur += 17;
			m += 4;
		}
		ans++;
	}	
	if (cur >= d) {
		std::cout << "YES " << ans << "\n";
	} else {
		std::cout << "NO " << cur << "\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
