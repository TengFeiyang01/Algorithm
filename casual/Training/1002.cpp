#include <bits/stdc++.h>


#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
const int mod = 1e9 + 7;
std::vector<std::array<ll, 3>> dp(N + 1);

//因为题目要求连续三天不去同一家，所以我们只需要考虑第i-1天和i-2天情况即可
//状态表示 dp[i][0/1/2]表示第i天去第0/1/2家的情况
//显然可以压缩为一维
void solve() {
    int n;
    std::cin >> n;
    std::cout << (dp[n][0] + dp[n][1] + dp[n][2]) % mod << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    dp[2][0] = dp[2][1] = dp[2][2] = 3;

    for (int i = 3; i <= N; ++i) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 2][1] + dp[i - 2][2]) % mod;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2] + dp[i - 2][0] + dp[i - 2][2]) % mod;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 2][0] + dp[i - 2][1]) % mod;
    }
    
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
