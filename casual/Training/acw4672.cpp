#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int k = 1;

void solve() {
	int n;
	std::cin >> n;
	int ans = 0;
	std::vector<std::tuple<std::string, int, int>> a(n);
	for (auto &[x, y, z] : a) {
		std::cin >> x >> y >> z;
	}

	auto b = a;
	std::sort(a.begin(), a.end(), [&](auto &x, auto &y) {
		return std::get<0> (x) != std::get<0> (y) ? std::get<0> (x) < std::get<0> (y) : std::get<2> (x) < std::get<2> (y);
	});

	std::sort(b.begin(), b.end(), [&](auto &x, auto &y) {
		return std::get<1> (x) != std::get<1> (y) ? std::get<1> (x) < std::get<1> (y) : std::get<2> (x) < std::get<2> (y);
	});

	for (int i = 0; i < n; ++i) {
		ans += std::get<2> (a[i]) == std::get<2> (b[i]);
	}

	std::cout << "Case #" << k++ << ": " << ans << "\n";
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
