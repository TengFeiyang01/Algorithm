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
const int N = 15;
int f[N][N]{0}; //f[i][j] 一共有i位，且最高位填 j 的方案数目

void init() {
	for (int i = 0; i < 10; ++i) f[1][i] = 1;
	for (int i = 2; i < 15; ++i)
		for (int j = 0; j <= 9; ++j)
			for (int k = j; k <= 9; ++k)
				f[i][j] += f[i - 1][k];
}
void solve() {
    int l, r;
	std::cin >> l >> r;
	auto dp = [&](int n) ->int {
		if (!n) return 1;
		std::vector<int> nums;
		while (n) nums.eb(n % 10), n /= 10;
		int res = 0, la = 0;
		for (int i = sz(nums) - 1; i >= 0; --i) {
			int x = nums[i];
			for (int j = la; j < x; ++j) {
				res += f[i + 1][j];
				if (x < la) break;
				la = x;
			}	
			if (!i) res++;
		}
		return res;
	};
	std::cout << dp(r) - dp(l - 1) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    init();
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
