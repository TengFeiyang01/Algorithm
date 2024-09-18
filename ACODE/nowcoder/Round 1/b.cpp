#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::unordered_map<int, i64> Red, Blue;
	std::string s;
	std::cin >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'R') {
			Red[a[i]]++;
		} else {
			Blue[a[i]]++;
		}
	}
	i64 ans = 0;
	for (auto[x, y] : Red) {
		if (Blue.count(x))
			ans += i64(y * Blue[x]);
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
