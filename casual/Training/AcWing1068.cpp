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

void solve() {
    int n;
    std::cin >> n;
 	std::vector<int> w(n << 1 | 1), sum(n << 1 | 1);
 	vector f(n << 1 | 1, std::vector<int>(n << 1 | 1, inf));
 	vector g(n << 1 | 1, std::vector<int>(n << 1 | 1, -inf));
 	for (int i = 1; i <= n; ++i) std::cin >> w[i], w[i + n] = w[i];
 	for (int i = 1; i <= n << 1; ++i) sum[i] = sum[i - 1] + w[i];

 	for (int len = 1; len <= n; ++len)
 		for (int l = 1; l + len - 1 <= n << 1; ++l) {
 			int r = l + len - 1;
 			if (len == 1) f[l][r] = g[l][r] = 0;
 			else {
 				for (int k = l; k < r; ++k) {
 					f[l][r] = std::min(f[l][r], f[l][k] + f[k + 1][r] + sum[r] - sum[l - 1]);
 					g[l][r] = std::max(g[l][r], g[l][k] + g[k + 1][r] + sum[r] - sum[l - 1]);
 				}
 			}
 		}
 	int ans1 = inf;
 	int ans2 = -inf;
 	for (int i = 1; i <= n; ++i) {
 		ans1 = std::min(ans1, f[i][i + n -1]);
 		ans2 = std::max(ans1, g[i][i + n -1]);
 	}
 	std::cout << ans1 << "\n" << ans2;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
