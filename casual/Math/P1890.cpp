#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

// https://www.luogu.com.cn/problem/P1890
// gcd+倍增
void solve() {
	int n, m;
	std::cin >> n >> m;
	int lg = std::__lg(n);
	std::vector f(n, std::vector<int>(lg + 1));
	for (int i = 0; i < n; ++i) {
		std::cin >> f[i][0];
	}    
	for (int j = 1; 1 << j < n; ++j) {
		for (int i = 0; i + (1 << j) - 1 < n; ++i) {
			f[i][j] = std::__gcd(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
		}
	}
	for (int i = 0; i < m; ++i) {
		int l, r;
		std::cin >> l >> r;
		--l, --r;
		int k = std::__lg(r - l + 1);
		std::cout << std::__gcd(f[l][k], f[r - (1 << k) + 1][k]) << "\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
