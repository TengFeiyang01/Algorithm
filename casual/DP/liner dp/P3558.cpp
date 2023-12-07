#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> nums[i];
    }
    std::vector<int> dp(3, inf);
    dp[nums[0] + 1] = 0;
    for (int i = 1; i < n; ++i) {
    	std::vector<int> ndp(3, inf);
    	int pre = nums[i - 1];
    	if (nums[i] == -1) {
    		ndp[0] = dp[0];
    		ndp[1] = pre == 1 ? std::min(dp[0], dp[1]) + 1 : inf;
    		ndp[2] = pre == 1 ? std::min({dp[0], dp[1], dp[2]}) + 2 : dp[2] + 2;
    	} else if (nums[i] == 0) {
    		ndp[0] = dp[0] + 1;
    		ndp[1] = std::min(dp[0], dp[1]);
    		ndp[2] = pre == 1 ? std::min({dp[0], dp[1], dp[2]}) + 1 : dp[2] + 1;
    	} else {
    		ndp[0] = dp[0] + 2;
    		ndp[1] = pre == -1 ? std::min(dp[0], dp[1]) + 1 : dp[0] + 1;
    		ndp[2] = std::min({dp[2], dp[0], dp[1]});
    	}
    	dp.swap(ndp);
    }
    int ans = std::ranges::min(dp);
    if (ans >= inf) {
        std::cout << "BRAK\n";
    } else {
        std::cout << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
