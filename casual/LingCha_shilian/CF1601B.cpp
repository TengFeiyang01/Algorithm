#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
    	std::cin >> b[i];
    }
    std::vector<int> dp(n + 1, inf), pre(n + 1, -1);
    std::queue<int> q;
    
    q.push(n);
    dp[n] = 0;
    int h = n;

    // h是能跳到最高的位置
    while (!q.empty()) {
    	int x = q.front(); q.pop();
    	int y = x + b[x];
        // 最小也得是跳到比之前高的位置 不然不如不跳
    	for (int i = y - h + 1; i <= a[y]; ++i) {
    		q.push(y - i);
    		dp[y - i] = dp[x] + 1;
    		pre[y - i] = x;
    		h = std::min(h, y - i);
    	}
    }	
    if (dp[0] == inf) {
    	std::cout << "-1\n";
    } else {
    	std::cout << dp[0] << "\n";
    	std::vector<int> ans;
    	int x = 0;
    	while (x != n) {
    		ans.push_back(x);
    		x = pre[x];
    	}
    	for (int x : std::views::reverse(ans)) {
    		std::cout << x << " ";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
