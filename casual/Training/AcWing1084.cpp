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
const int N = 14;

int f[N][111];

int l, r, mod;
int a[N];

int dp(int pos, bool is_limit, int mask) {
	if (pos == 0) return mask == 0;
	if (!is_limit && ~f[pos][mask]) return f[pos][mask];
	int ans = 0;
	int up = is_limit ? a[pos] : 9;
	for (int i = 0; i <= up; ++i) {
		ans += dp(pos - 1, is_limit && i == up, (mask + i) % mod);
	}
	return is_limit ? ans : f[pos][mask] = ans;
}

ll calc(int n) {
	int idx = 0;
	memset(f, -1, sizeof f);
	while (n) a[++idx] = n % 10, n /= 10;
	return dp(idx, true, 0);
}


void solve() {
	while (std::cin >> l >> r >> mod)
		std::cout << calc(r) - calc(l - 1) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
