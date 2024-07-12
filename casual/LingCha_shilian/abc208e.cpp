#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    i64 k;
    std::cin >> s >> k;

    std::map<std::pair<int, i64>, i64> memo;
    
    auto dfs = [&](auto &&self, int idx, i64 mul, bool is_limit, bool is_num) ->i64 {
        if (idx == s.size()) {
            if (is_num && mul <= k) {
                return 1;
            }
            return 0;
        } 

        if (!is_limit && is_num && memo.count({idx, mul})) {
            return memo[{idx, mul}];
        }
        i64 res = 0;
        if (!is_num) {
            res += self(self, idx + 1, mul, false, false);
        }
        int up = is_limit ? s[idx] - '0' : 9;

        for (int d = is_num ? 0 : 1; d <= up; ++d) {
            res += self(self, idx + 1, mul * d, is_limit && d == up, true);
        }

        if (!is_limit && is_num) {
            memo[{idx, mul}] = res;
        }
        return res;
    };
    std::cout << dfs(dfs, 0, 1, true, false);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}