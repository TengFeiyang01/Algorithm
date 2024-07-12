#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::string s;
	std::cin >> s;
	for (int i = k - 1; i < n; ++i) {
		std::cout << s[i];
	}
	if ((n - k + 1) % 2) {
		std::reverse(s.begin(), s.begin() + k - 1);
	}

	std::cout << s.substr(0, k - 1);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
