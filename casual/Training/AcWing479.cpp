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
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    vector f(n, std::vector<int>(n));
    vector g(n, std::vector<int>(n));

    for (int len = 1; len <= n; ++len) 
    	for (int l = 0; l + len - 1 < n; ++l) {
    		int r = l + len - 1;
    		if (len == 1) {
    			f[l][r] = a[l];
    			g[l][r] = l;
    		} else {
    			for (int k = l; k <= r; ++k) {
    				int left = k == l ? 1 : f[l][k - 1];
    				int right = k == r ? 1 : f[k + 1][r];
					int sc = left * right + a[k];
					if (sc > f[l][r]) {
						f[l][r] = sc;
						g[l][r] = k;
					}
    			}
    		}
    	}
    std::cout << f[0][n - 1] << "\n";

/*    std::function<void(int, int)> dfs = [&](int l, int r) {
        if (l > r) return;
        int k = g[l][r];
        std::cout << k + 1 << " ";
        dfs(l, k - 1);
        dfs(k + 1, r);
    };
*/
    auto dfs = [&](auto& self, int l, int r) ->void {
        if (l > r) return;
        int k = g[l][r];
        std::cout << k + 1 << " ";
        self(self, l, k - 1);
        self(self, k + 1, r);
    };

    dfs(dfs, 0, n - 1);

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
