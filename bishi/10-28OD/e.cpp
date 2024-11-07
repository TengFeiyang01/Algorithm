#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q, x, y;
    std::cin >> n >> q >> x >> y;
    std::vector<int> a(n);
    int lg = 31;
    std::vector<std::vector<i64>> dp_exact(n, std::vector<i64>(lg + 1));
    std::vector<std::vector<i64>> dp_up_to(n, std::vector<i64>(lg + 1));
    std::vector<std::vector<int>> next(n, std::vector<int>(lg + 1));

    for (int i = 0; i < n; ++i) {
    	std::cin >> next[i][0];
    	next[i][0]--;
    }

    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
    	i64 p = 0;
    	if (a[next[i][0]] > a[i]) {
    		p = x;
    	} else {
    		p = y;
    	}
    	dp_exact[i][0] = p;
    	dp_up_to[i][0] = std::max(0LL, p);
    	// std::cout << p << "\n";
    }
    for (int j = 1; j <= lg; ++j) {
    	for (int k = 0; k < n; ++k) {
    		next[k][j] = next[next[k][j - 1]][j - 1];
    	}
    }
    for (int j = 1; j <= lg; ++j) {
        for (int i = 0; i < n; ++i) {
            dp_exact[i][j] = dp_exact[i][j - 1] + dp_exact[next[i][j - 1]][j - 1];
            dp_up_to[i][j] = std::max(0LL, dp_exact[i][j - 1] + dp_up_to[next[i][j - 1]][j - 1]);
            dp_up_to[i][j] = std::max(dp_up_to[i][j], dp_exact[i][j]);
        }
    }

    for (int i = 0; i < q; ++i) {
        int u, k;
        std::cin >> u >> k;
        u--; 

        i64 res = 0, p = u, s = 0;
        for (int j = lg; j >= 0; j--) {
        	if (k >> j & 1) {
        		res = std::max(res, s + dp_up_to[p][j]);
        		s += dp_exact[p][j];
        		p = next[p][j];
        	}
        }
        std::cout << res << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
