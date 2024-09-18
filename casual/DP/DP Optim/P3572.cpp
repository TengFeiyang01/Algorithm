#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }	
    std::cin >> m;
   	std::vector<int> dp(n);
    for (int i = 0, k; i < m; ++i) {
    	std::cin >> k;
    	std::deque<int> q;
    	q.push_back(0);
    	dp[0] = 0;
    	for (int i = 1; i < n; ++i) {
    		while (!q.empty() and q.front() < i - k) q.pop_front();
    		dp[i] = dp[q.front()] + (a[q.front()] <= a[i]);
            // 两个位置dp值相同的话 那么最低的那个位置最优秀
    		while (!q.empty() and dp[q.back()] > dp[i] || (dp[q.back()] == dp[i] and a[q.back()] <= a[i])) q.pop_back();
    		q.push_back(i);
    	}
    	std::cout << dp.back() << "\n";
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
