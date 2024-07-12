#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;
	int n = s.size();
	int ans = 0;
	auto t = s;
	std::vector<int> st(n);
	std::queue<int> one, zero;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			one.push(i);
		} else {
			zero.push(i);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!st[i]) {
			st[i] = true;
			if (t[i] == '1') {
				one.pop();
				if (zero.size()) {
					int u = zero.front();
					zero.pop();
					st[u] = 1;
					t[u] = '1';
					t[i] = '0';
				}
			} else {
				zero.pop();
				if (one.size()) {
					int u = one.front();
					one.pop();
					st[u] = 1;
					t[u] = '0';
					t[i] = '1';
				}
			}
		}
	}

	
	for (int i = 0; i < n; ++i) {
		if (s[i] == t[i]) {
			std::cout << n - i << "\n";
			return;
		}
	}

	std::cout << ans << "\n";
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
