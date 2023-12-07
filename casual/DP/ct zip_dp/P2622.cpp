#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    int x, limit = (1 << n) - 1;
    std::vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) {
    	for (int j = 0; j < n; ++j) {
            std::cin >> x;
    		if (x == 1) {
    			a[i] |= 1 << j;
    		} 
            if (x == -1) {
    			b[i] |= 1 << j;
    		}
    	}
    }
    std::vector dp(1 << n, inf);
    std::vector<bool> st(1 << n);
    std::queue<int> q;
    q.push(0);
    dp[0] = 0;

    while (!q.empty()) {
    	int u = q.front(); q.pop();
        st[u] = 0;
    	for (int i = 0; i < m; ++i) {
    		int state = (u | a[i]) & (~b[i]);
            if (state > limit) continue;
    		if (dp[state] > dp[u] + 1) {
    			dp[state] = dp[u] + 1;
    			if (!st[state]) {
    				st[state] = 1;
    				q.push(state);
    			}
    		}
    	}
    }
    std::cout << (dp[limit] == inf ? -1 : dp[limit]);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
