#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, d, k;
    std::cin >> n >> d >> k;
    i64 s = 0;
    std::vector<std::array<i64, 2>> a(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i][0] >> a[i][1];
    	if (a[i][1] > 0) {
    		s += a[i][1];
    	}
    }
    if (s < k) {
    	std::cout << -1 << "\n";
    	return;
    }

    int l = 0, r = inf;
    while (l < r) {
    	int mid = l + r >> 1;
    	// [d-mid, d+mid]
    	int lp = std::max(1, d - mid), rp = std::min(d + mid, inf);
    	std::vector<i64> dp(n + 1);
    	std::deque<int> q;
    	dp[0] = 0;
    	bool ok = false;
    	for (int i = 1, j = 0; i <= n; ++i) {
    		for (;j < i && a[i][0] - a[j][0] >= lp; j++) {
    			if (q.empty()) {
    				q.push_back(j);
    			} else {
    				while (!q.empty() and dp[j] >= dp[q.back()]) {
    					q.pop_back();
    				}
    				q.push_back(j);
    			}
    		}
    		while (!q.empty() and a[i][0] - a[q.front()][0] > rp) {
    			q.pop_front();
    		}
    		if (!q.empty()) {
    			dp[i] = dp[q.front()] + a[i][1];
    		} else {
    			dp[i] = -1e15;
    		}
    		if (dp[i] >= k) {
    			ok = true;
    		}
    	}
    	if (ok) {
    		r = mid;
    	} else {
    		l = mid + 1;
    	}
    }
    std::cout << l << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
