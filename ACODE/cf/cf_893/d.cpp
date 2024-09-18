#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::vector<int> ans(n + 1);

    //l0 0的连续段 l1 1的连续段

    auto work = [&]() {
        //f[i][j] 从 i 开始花费 j 可以得到的最大的连续段 '1' 长度
    	std::vector f(n + 1, std::vector<int>(k + 1));
    	std::vector<int> g(n + 1, -1);
    	for (int i = n - 1; i >= 0; --i) {
    		f[i] = f[i + 1];
    		int cost = 0;
    		for (int j = i; j < n; ++j) {
    			cost += (s[j] == '0');
    			if (cost <= k) { 
    				f[i][cost] = std::max(f[i][cost], j - i + 1);
    			}
    		}
    		for (int j = 1; j <= k; ++j) {
    			f[i][j] = std::max(f[i][j], f[i][j - 1]);
    		}
    	}

        //h[i] 获得长度为i的连续 '0' 段的最小代价
    	std::vector<int> h(n + 1, k + 1);
    	h[0] = 0;
        for (int i = 0; i <= n; ++i) {
    		if (i > 0) {
    			int cost = 0;
    			for (int j = i - 1; j >= 0; --j) {
    				cost += (s[j] == '1');
    				h[i - j] = std::min(h[i - j], cost);
    			}
    		}
    		for (int j = 0; j <= i; ++j) {
    			if (h[j] <= k) {
    				g[j] = std::max(g[j], f[i][k - h[j]]);
    			}
    		}
    	}
    	for (int a = 1; a <= n; ++a) {
    		for (int i = 0; i <= n; ++i) {
    			if (g[i] != -1) {
    				ans[a] = std::max(ans[a], i * a + g[i]);
    			}
    		}
    	}
    };

    work();
    std::reverse(s.begin(), s.end());
    work();

    for (int i = 1; i <= n; ++i) {
    	std::cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
