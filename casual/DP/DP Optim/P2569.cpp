#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, w;
    std::cin >> n >> m >> w;
    std::vector<int> AP(n + 1), BP(n + 1), AS(n + 1), BS(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> AP[i] >> BP[i] >> AS[i] >> BS[i];
    } 
    std::vector dp(n + 1, std::vector(m + 1, -inf));
    std::deque<int> q;

    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 0; j <= std::min(m, AS[i]); ++j) {
    		dp[i][j] = -1 * j * AP[i];
    	}
    	for (int j = 0; j <= m; ++j) {
    		dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
    	}
    	// 在第 i-w-1 天的基础上买
    	// dp[i][j] = max(dp[i-w-1][k] - (j - k) * AP[i]) k的范围是 [j-AS[i], j]  
        if (i <= w) continue;
        q.clear();
    	for (int j = 0; j <= m; ++j) {
            while (!q.empty() and j - AS[i] > q.front()) q.pop_front();
            if (!q.empty()) dp[i][j] = std::max(dp[i][j], dp[i - w - 1][q.front()] + (q.front() - j) * AP[i]);
    		while (!q.empty() and dp[i - w - 1][j] + (j - q.back()) * AP[i] >= dp[i - w - 1][q.back()]) q.pop_back();
            q.push_back(j);
    	}
    	// dp[i][j] = max(dp[i - w - 1][k] + (k - j) * BS[i]) k的范围是[j, j+BS[i]]
        q.clear();
    	for (int j = m; j >= 0; --j) {
            while (!q.empty() and j + BS[i] < q.front()) q.pop_front();
            if (!q.empty()) dp[i][j] = std::max(dp[i][j], dp[i - w - 1][q.front()] + (q.front() - j) * BP[i]);
            while (!q.empty() and dp[i - w - 1][q.back()] <= dp[i - w - 1][j] + (j - q.back()) * BP[i]) q.pop_back();
            q.push_back(j);
    	}
    }

    // std::cout << std::ranges::max(dp[n]) << "\n";
    std::cout << dp[n][0];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
