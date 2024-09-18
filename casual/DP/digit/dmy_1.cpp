#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

i64 f[20][2][10][4];

void solve() {
    i64 l, r;
    std::cin >> l >> r;

	std::vector<int> a(20);

    auto dp = [&](i64 n) ->i64 {
    	if (n <= 100) return 0;
		int len = 0;
	    while (n) {
	    	a[++len] = n % 10;
	    	n /= 10;
	    }
	    memset(f, -1, sizeof f);
	    std::function<i64(int, bool, int, int, bool, bool)> dfs = 
	    		[&](int idx, bool ok, int pre, int inc, bool is_limit, bool is_num) ->i64 {
	    	if (idx == 0) return ok;
	    	if (!is_limit and is_num and f[idx][ok][pre][inc] != -1) return f[idx][ok][pre][inc];
	    	
	    	i64 res = 0;
	    	if (!is_num) res += dfs(idx - 1, false, 9, 0, false, false);

	    	int up = is_limit ? a[idx] : 9;
	    	
	    	for (int i = is_num ? 0 : 1; i <= up; ++i) {
	    		int cnt = i > pre ? std::min(inc + 1, 3) : 1;
	    		res += dfs(idx - 1, ok or cnt == 3, i, cnt, is_limit and i == up, true);
	    	}
	    	if (!is_limit and is_num) f[idx][ok][pre][inc] = res;
	    	return res;
	    };
	    return dfs(len, false, 9, 0, true, false);
    };
    std::cout << dp(r) - dp(l - 1) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
