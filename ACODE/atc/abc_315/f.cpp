#include <bits/stdc++.h>

using i64 = long long;
using PII = std::pair<int, int>;

constexpr int K = 30;
constexpr double inf = 1E9;

void solve() {
    int N;
    std::cin >> N;

    std::vector<int> X(N), Y(N);
    for (int i = 0; i < N; ++i) {
    	std::cin >> X[i] >> Y[i];
    }

    std::vector dp(N, std::vector<double>(K, inf));
    double ans = inf;
    dp[0][0] = 0;
    for (int i = 0; i < N - 1; ++i) {
    	for (int j = 0; j < K; ++j) {
    		for (int x = i + 1; x < N and j + (x - i - 1) < K; ++x) {
    			int nj = j + x - i - 1;
    			dp[x][nj] = std::min(dp[x][nj], dp[i][j] + std::sqrt((X[i] - X[x]) * (X[i] - X[x]) + (Y[i] - Y[x]) * (Y[i] - Y[x])));
    		}
    	}
    }

    for (int i = 0; i < K; ++i) {
        ans = std::min(ans, dp[N - 1][i] + (i == 0 ? 0 : 1 << (i - 1)));
    }

    std::cout << std::fixed << std::setprecision(10) << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
