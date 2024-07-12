#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;

i64 dp[64][2][2][2];
int f[500]{0};

void solve() {
	i64 m, L;
	std::cin >> m >> L;
	std::vector<int> a(100);
	int len = 0;
	memset(dp, -1, sizeof dp);
	for (i64 x = L; x; x >>= 1) a[len++] = x & 1;
	std::vector<int> A(m);
	for (int i = 0; i < m; ++i) std::cin >> A[i];

	auto calc = [&](int is_limit, int s, int t) {
		int res = 0, hi = is_limit ? L % 128 : 127;
		for (int i = 0; i <= hi; ++i) {
			int f = 1;
			for (int j = 0; j < m and f; ++j)
				if (i + j < 128) f &= (__builtin_parity(i + j) ^ s) == A[j];
				else f &= (__builtin_parity(i + j) ^ s ^ t) == A[j];
			res += f;
		}
		return res;
	};

	std::function<i64(int, int, int, int)> dfs = [&](int idx, int is_limit, int s, int t) {
		i64 &res = dp[idx][is_limit][s][t];
		if (~res) return res;
		if (idx <= 6) return res = calc(is_limit, s, t);
		res = 0;
		int up = is_limit ? a[idx] : 1;
		for (int i = 0; i <= up; ++i)
			res += dfs(idx - 1, is_limit and i == up, s ^ i, i & (!t));
		return res;
	};

	std::cout << dfs(len - 1, 1, 0, 0) << "\n";
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
