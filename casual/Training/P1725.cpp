#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 2e5 + 13;
int n, m, nums[N], l, r;

void solve() {
    std::cin >> n >> l >> r;
    for (int i = 0; i <= n; ++i) std::cin >> nums[i];
    std::deque<int> dq;
	int dp[N];
	memset(dp, -0x3f, N);
	dp[0] = 0;
	int p = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		while (!dq.empty() && dp[dq.front()] <= dp[p]) dq.pop_front();
		dq.push_back(p);
		while (dq.front() + r < i) dq.pop_front();
		dp[i] = dp[dq.front()] + nums[i];
		p++;
	}	
	for (int x = n - r + 1; x <= n; ++x) {
		ans = std::max(dp[x], ans);
	}
	std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
