#include <bits/stdc++.h>
using namespace std;

int solution(string &S) {
    int n = S.size();
    if (n <= 1) return 0;
    vector<array<int, 2>> dp(n);
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if ((S[i] == ')' || S[i] == '?') && (S[i - 1] == '(' || S[i - 1] == '?')) {
            dp[i][1] = i > 1 ? (max(dp[i - 2][0], dp[i - 2][1]) + 2) : 2;
        } 

        if ((S[i] == ')' || S[i] == '?') && (S[i - 1] == ')' || S[i - 1] == '?')) {
            if (i - dp[i - 1][1] - 1 >= 0 && (S[i - dp[i - 1][1] - 1] == '(' || S[i - dp[i - 1][1] - 1] == '?')) {
                dp[i][1] = dp[i - 1][1] + (i - dp[i - 1][1] - 2 >= 0 ? max(dp[i - dp[i - 1][1] - 2][0], dp[i - dp[i - 1][1] - 2][1]) : 0) + 2;
            }
        }
        std::cout << dp[i][0] << " " << dp[i][1] << "\n";

        ans = max(ans, dp[i][1]);
    }
    return ans;
}


void solve() {
    string s;
    std::cin >> s;
    std::cout << solution(s) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}