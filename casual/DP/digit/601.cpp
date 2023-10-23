#include <bits/stdc++.h>
 
using i64 = long long;
constexpr int len = 17;

i64 cnt(i64 n, int k) {
	auto s = std::to_string(n);
	i64 dp[len][len];
	memset(dp, -1, sizeof dp);

	std::function<i64(int, i64, bool, bool)> dfs = [&](int idx, i64 count, bool is_limit, bool is_num) ->i64 {
		if (idx == (int)s.size()) return count;
		if (!is_limit and is_num and dp[idx][count] != -1) return dp[idx][count];
		i64 res = 0;
		if (!is_num) res = dfs(idx + 1, count, false, false);
		int up = is_limit ? s[idx] - '0' : 9;

		for (int d = is_num ? 0 : 1; d <= up; ++d)
			res += dfs(idx + 1, count + (d == k), is_limit and d == up, true);
		if (!is_limit and is_num) dp[idx][count] = res;
		return res;
	};
	return dfs(0, 0, true, false);
}

void solve() {
    i64 l, r;
    std::cin >> l >> r;
    for (int i = 0; i < 10; ++i) {
    	std::cout << cnt(r, i) - cnt(l - 1, i) << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
