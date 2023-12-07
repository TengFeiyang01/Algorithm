#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int N, Q;
	std::cin >> N >> Q;
	std::string s;
	std::cin >> s;

	std::vector<int> f(N);
	for (int i = 1; i < N; ++i) {
		f[i] += f[i - 1] + (s[i] == s[i - 1]);
	}	

	// f[i] 到为止的位置中 相同的字母的位置的个数

	while (Q--) {
		int l, r;
		std::cin >> l >> r;
		--l, --r;
		std::cout << f[r] - f[l] << "\n";
	}

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
