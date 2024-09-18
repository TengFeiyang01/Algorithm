#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    if (m > n * n) {
    	std::cout << "-1\n";
    	return;
    } else {
    	std::vector ans(n, std::vector<int>(n));
    	for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (ans[i][j] == 0) {
                    if (i == j) {
                        if (m > 0) {
                            ans[i][j] = 1;
                            m--;
                        }
                    } else {
                        if (m >= 2) {
                            ans[i][j] = 1;
                            ans[j][i] = 1;
                            m -= 2;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
	    	for (int j = 0; j < n; ++j) {
	    		std::cout << ans[i][j] << " \n"[j == n - 1];
	    	}
	    }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}