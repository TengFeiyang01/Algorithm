#include <bits/stdc++.h>
 
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

// 思路：

// 1、显然是先求出对于每层任取任意本书能获得的最大价值。

// 2、然后背包一下。

// 1：

// 对于一层书任意j本，那么一定是从左端取k本，右端取 j-k本，求个前缀和然后枚举 j和k即可。每层n^2的dp

void solve() {
    int n, k, m, t;
    std::cin >> n >> m;
    std::vector<int> f(m + 1);
    while (n--) {
    	std::cin >> k;
    	std::vector<int> s(k + 1);
    	for (int i = 1; i <= k; ++i) {
    		std::cin >> s[i];
    		s[i] += s[i - 1];
    	}
    	std::vector<int> mx(k + 1);
    	for (int i = 1; i <= k; ++i) // 计算选 i 个物品的最大价值和
    		for (int j = 0; j <= i; ++j)  // 枚举前缀长度
    			mx[i] = std::max(mx[i], s[j] + s[k] - s[k - i + j]);

    	t = std::min(t + k, m);    // 优化循环上界
    	for (int c = t; c >= 0; --c) {
        		for (int j = 1; j <= k && j <= c; ++j) {
                    f[c] = std::max(f[c], f[c - j] + mx[j]);
    		}
    	}
    }
    std::cout << f[m];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
