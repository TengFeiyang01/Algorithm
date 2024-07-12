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
#if 0 
int f[N][N]{0}; //f[i][j] 一共有i位，且最高位填 j 的方案数目

void init() {
	for (int i = 0; i < 10; ++i) f[1][i] = 1;
	for (int i = 2; i < 15; ++i)
		for (int j = 0; j <= 9; ++j)
			for (int k = 0; k <= 9; ++k) 
				if (abs(j - k) >= 2)
					f[i][j] += f[i - 1][k];
}
void solve() {
    int l, r;
    std::cin >> l >> r;
	auto dp = [&](int n) ->int {
		if (!n) return 0;
		std::vector<int> nums;
		while (n) nums.eb(n % 10), n /= 10;
		int res = 0, la = -2;
		for (int i = sz(nums) - 1; i >= 0; --i) {
			int x = nums[i];
			for (int j = i == sz(nums) - 1; j < x; ++j) {
				if (abs(j - la) >= 2) {
					res += f[i + 1][j];
				}
			}	
			if (abs(x - la) >= 2) la = x;
			else break;
			if (!i) res++;
		}
		//特殊判读前导0
		for (int i = 1; i < nums.size(); ++i) {
			for (int j = 1; j <= 9; ++j) {
				res += f[i][j];
			}
		}

		return res;
	};
    std::cout << dp(r) - dp(l - 1) << "\n";
}
#endif
int f[N][N]{0};
int a[N];

int dp(int idx, bool is_num, bool is_limit, int mask) {
	if (idx == 0) return 1;
	if (!is_limit && is_num && ~f[idx][mask]) return f[idx][mask];
	int res = 0, up = is_limit ? a[idx] : 9;
	for (int i = 0; i <= up; ++i) {
		if (abs(mask - i) <= 2) continue;
		if (!is_num && i == 0) res += dp(idx - 1, false, is_limit && i == a[idx], mask);
		else res += dp(idx - 1, true, is_limit && i == a[idx], i);
	}
	if (!is_limit && is_num) return f[idx][mask] = res;
	return res;
} 

int calc(int n) {
	if (!n) return 0;
	int idx = -1;
	memset(f, -1, sizeof f);
	while (n) a[++idx] = n % 10, n /= 10;
	return dp(idx, true, true, -2);
}

void solve() {
	int l, r;
	std::cin >> l >> r;

	std::cout << calc(r) - calc(l - 1) << "\n";
}


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    //init();
    
    solve();

    return 0;
}
