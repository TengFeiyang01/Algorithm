#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A) {
    int n = A.size();
    vector<array<long long, 2>> dp(n + 1);
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + A[i - 1]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - A[i - 1]);
    }
    return dp[n][0] % 1000000000;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    std::cout << solution(a) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}