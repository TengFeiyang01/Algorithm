#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    i64 ans = 0;

    // std::vector dp(n, std::vector<i64>(2));
    // //我们设 dp[i][0/1]表示前 i个数，满足 f(l,i)==0或 f(l,i)==1的l的数量，
    // if (s[0] == '1') {
    //     dp[0][1] = 1;
    // } else {
    //     dp[0][0] = 1;
    // }
    // ans += dp[0][1];
    // for (int i = 1; i < n; ++i) {
    // 	if (s[i] == '0') {
    // 		dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
    // 		dp[i][0] = 1;
    // 	} else {
    // 		dp[i][0] = dp[i - 1][1];
    // 		dp[i][1] = dp[i - 1][0] + 1;
    // 	}
    // 	ans += dp[i][1];
    // }

    std::array<i64, 2> dp{0, 0};
    for (auto c : s) {
        std::array<i64, 2> f{0, 0};
        if (c == '0') {
            f[0] = 1;
            f[1] = dp[0] + dp[1];
        } else {
            f[1] = 1 + dp[0];
            f[0] = dp[1];
        }
        ans += f[1];
        dp = f;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}