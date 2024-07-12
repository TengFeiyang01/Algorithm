#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n, s, k;
	std::cin >> n >> s >> k;
	std::vector<std::array<int, 2>> a(n);
	i64 ans = 0;
	for (auto &[x, y] : a) {
		std::cin >> x >> y;
		ans += x * y;
	}   
	std::cout << ans + k * (ans < s);

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
