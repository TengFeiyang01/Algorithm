#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int N = 1e7;

void solve() {
	int n;
	std::string s;
	std::cin >> n >> s;
	if (n == 1 && s[0] == '0') {
		std::cout << 1 << "\n";
		return;
	}
	std::vector<int> b(10);
	for (auto c : s) {
		b[c - '0']++;
	}

	i64 ans = 0;
	for (i64 i = 1LL; i <= 100000001; ++i) {
		i64 x = i * i;
		int ok = 1;
		std::vector<int> a(10, 0);
		int c = 0;
		while (x) {
			a[x % 10]++;
			x /= 10;
			c++;
		} 

		if (c > n) break;
		if (a[0] > b[0]) continue;
		for (int j = 1; j < 10; ++j) 
			if (a[j] != b[j]) {
				ok = 0;
				break;
			}
		ans += ok;
	}
	
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
	solve();

    return 0;
}
