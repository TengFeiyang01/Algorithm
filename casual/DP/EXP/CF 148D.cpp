#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int w, b;
    std::cin >> w >> b;
    std::vector dp(w + 1, std::vector<double>(b + 1));
    for (int i = 1; i <= w; ++i) {
    	dp[i][0] = 1;
    }
    for (int i = 1; i <= b; ++i) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= w; ++i)
    	for (int j = 1; j <= b; ++j) {
    		dp[i][j] += double(i) / (i + j);
    		if (j >= 2) {
    			dp[i][j] += double(j) / (i + j) * (j - 1) / (i + j - 1) * i / (i + j - 2) * dp[i - 1][j - 2];
    		}
    		if (j >= 3) {
    			dp[i][j] += double(j) / (i + j) * (j - 1) / (i + j - 1) * (j - 2) / (i + j - 2) * dp[i][j - 3];
    		}
    	}
    std::cout.precision(9);
    std::cout << dp[w][b] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
