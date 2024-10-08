#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> b(m);
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0];
    	a[i][1] = i;
    }
    for (int i = 0; i < m; ++i) {
    	std::cin >> b[i];
    }
    
    std::sort(a.begin(), a.end(), std::greater());

    std::vector f(m, std::vector<int>(n, n + 1));
    for (int i = 0; i < m; ++i) {
    	for (int j = 0; j < n; ++j) {
    		int l = j + 1 - ((b[i] - 1) / a[j][0] + 1);
    		if (l >= 0) {
    			f[i][l] = std::min(f[i][l], j + 1);
    		}
    	}
    	for (int j = n - 2; j >= 0; --j) {
    		f[i][j] = std::min(f[i][j], f[i][j + 1]);
    	}
    }



    std::vector<int> dp(1 << m, n + 1);
    dp[0] = 0;
    for (int s = 1; s < (1 << m); s++) {
        for (int i = 0; i < m; i++) {
            if (s >> i & 1) {
                int t = s ^ (1 << i);
                if (dp[t] < n) {
                    dp[s] = std::min(dp[s], f[i][dp[t]]);
                }
            }
        }
    }

    if (dp.back() <= n) {
        std::cout << "YES\n";
        std::vector<std::vector<int>> ans(m);
        int s = (1 << m) - 1;
        while (s > 0) {
            for (int i = 0; i < m; i++) {
                if (s >> i & 1) {
                    int t = s ^ (1 << i);
                    if (dp[t] < n && f[i][dp[t]] == dp[s]) {
                        for (int j = dp[t]; j < dp[s]; j++) {
                            ans[i].push_back(a[j][1] + 1);
                        }
                        s = t;
                        break;
                    }
                }
            }
        }
        for (auto x : ans) {
            std::cout << x.size();
            for (auto y : x) {
                std::cout << " " << y;
            }
            std::cout << "\n";
        }
    } else {
        std::cout << "NO\n";
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}