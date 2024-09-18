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
#include <stack>
#include <numeric>
#include <cmath>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
ll dp[N]{0};

//转化为打家劫舍， 每个位置存放删除当前数的分数, 即 sum[i] = a[i] * cnt[a[i]],
//每次偷sum[i], 则sum[i - 1], sum[i + 1] 不能偷


void solve() {
	int n;
	std::cin >> n;
	std::vector<ll> a(n), sum(N, 0);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		sum[a[i]] += a[i];
	}
	dp[0] = 0;
	dp[1] = sum[0];
	for (int i = 2; i <= sum.size(); ++i) {
		dp[i] = std::max(dp[i - 1], dp[i - 2] + sum[i - 1]);
	}
	std::cout << dp[sum.size()];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
