#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	i64 s, t, A, B;
	std::cin >> A >> B >> s >> t;
	i64 ans = 0;

	for (i64 i = 1; i <= B; ++i) {
		i64 x = A % i;
		ans += std::max(0LL, std::min(x, t) - s + 1);

		i64 p = A / i;
		ans += p * std::max(0LL, std::min(i - 1, t) - s + 1);
		if (s == 0) ans--;
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
