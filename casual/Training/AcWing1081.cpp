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
const int N = 32;

std::vector f(N, std::vector<int>(N));

void init() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j)
			if (!j) f[i][j] = 1;
			else f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
	}
}

void solve() {
    int k, b, x, y;
    std::cin >> x >> y >> k >> b;
	
	auto dp = [&](int n) ->int{
		if (!n) return 0;
		std::vector<int> nums;
		while (n) nums.eb(n % b), n /= b;
		
		int res = 0, last = 0;	//last 前面多少个一
		for (int i = sz(nums) - 1; i >= 0; --i) {
			int cur = nums[i];
			
			if (cur) { //左分枝
				res += f[i][k - last];
				if (cur > 1) {
					if (k - last - 1 >= 0) res += f[i][k - last - 1];
					break;
				} else {
					last++;
					if (last > k) break;
				}
			} 
			if (!i && last == k) res++;
		}
		return res;
	};
	std::cout << dp(y) - dp(x - 1) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    init();

    solve();

    return 0;
}
