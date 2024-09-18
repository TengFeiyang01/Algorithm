#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, k, t;
    std::cin >> n >> m >> k >> t;
    std::vector val(n, std::vector(m, 0));
    for (int i = 0; i < k; ++i) {
    	int x, y, v;
    	std::cin >> x >> y >> v;
    	val[x - 1][y - 1] = v;
    }
    
    std::vector<i64> dp(m);
    for (int i = 0; i < m; ++i) {
    	dp[i] = val[0][i];
    }

    for (int i = 1; i < n; ++i) {
	    std::deque<int> q;
        std::vector<i64> ndp(m);
	    for (int p = 0; p <= t and p < m; ++p) {
	    	while (!q.empty() and dp[q.back()] < dp[p]) q.pop_back();
	    	q.push_back(p);
	    }    	
    	for (int j = 0; j < m; ++j) {
    		while (!q.empty() and q.front() < j - t) q.pop_front();
    		ndp[j] = dp[q.front()] + val[i][j];
    		while (!q.empty() and j + t + 1 < m and dp[q.back()] < dp[j + t + 1]) q.pop_back();
    		q.push_back(j + t + 1);
    	}
    	dp.swap(ndp);
    }
    std::cout << std::ranges::max(dp);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
