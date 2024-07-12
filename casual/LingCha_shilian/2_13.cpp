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
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

/*
https://codeforces.com/contest/1324/submission/193356533
https://codeforces.com/contest/1324/submission/193357512
https://codeforces.com/contest/1324/submission/193357666

我在 https://www.bilibili.com/video/BV1Xj411K7oF/ 中讲了，先把记忆化搜索写出来，再转成递推是最容易的。

那么定义 dfs(i,s)，i 表示当前在 a[i]，s 表示前面累计的和，返回最大分数。
那么 dfs(i,s) = max(dfs(i+1,(s+a[i])%h),dfs(i+1,(s+a[i]-1)%h)) + (l<=s<=r)
具体细节见代码（包含记忆化搜索、递推、空间优化）。
*/

void solve() {

   int n, h, l, r;
    std::cin >> n >> h >> l >> r;
    std::vector<int> a(n);
    for (int&v : a) std::cin >> v;
/* 
	//记忆化
	std::vector dp(n, std::vector<int>(h, -1));

	std::function<int(int, int)> f = [&](int i, int s) ->int {
		if (i == n) {
			if (l <= s && s <= r) {
				return 1;
			}
			return 0;
		}

		if (dp[i][s] != -1) return dp[i][s];

		int res = std::max(f(i + 1, (s + a[i]) % h), f(i + 1, (s + a[i] - 1) % h));
		if (i > 0 && l <= s && s <= r) res++;
		
		return dp[i][s] = res;
	};

	std::cout << f(0, 0);*/
	//std::vector f(n + 1, std::vector<int>(h));
	std::vector f(2, std::vector<int>(h));
	
	for (int s = l; s <= r; ++s) {
		//f[n][s] = 1;
		f[n & 1][s] = 1;
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int s = 0; s < h; ++s) {
			//f[i][s] = std::max(f[i + 1][(s + a[i]) % h], f[i + 1][(s + a[i] - 1) % h]);
			f[i & 1][s] = std::max(f[i & 1 ^ 1][(s + a[i]) % h], f[i & 1 ^ 1][(s + a[i] - 1) % h]);
			if (i > 0 && l <= s && s <= r) {
				f[i & 1][s]++;
			}
		}
	}
	std::cout << f[0][0];
	


}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
