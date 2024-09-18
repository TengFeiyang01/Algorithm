#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
std::vector<int> f(40001, 0);
std::vector<int> pal;

void solve() {
	int n;
	std::cin >> n;
	std::cout << f[n] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;

	for (int i = 1; i < 400; ++i) {
		int p = i;
		for (int x = i / 10; x > 0; x /= 10) {
			p = p * 10 + x % 10;
		}
		pal.push_back(p);
		if (i < 100) {
			p = i;
			for (int x = i; x > 0; x /= 10) {
				p = p * 10 + x % 10;
			}
			pal.push_back(p);
		}
	}
	f[0] = 1;
	for (int v : pal) {
		for (int j = v; j < 40001; ++j) {
			f[j] = (f[j] + f[j - v]) % 1000000007;
		}
	}

    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
