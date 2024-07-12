#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	int n;
	std::cin >> n;
	int x = -1;
	std::vector<std::pair<std::string, int>> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].first >> a[i].second;
		if (x == -1 or a[i].second < a[x].second) {
			x = i;
		}
	}
	for (int i = x; i < x + n; ++i) {
		std::cout << a[i % n].first << "\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
