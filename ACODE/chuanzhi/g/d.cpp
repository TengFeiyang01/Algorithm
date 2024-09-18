#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    i64 tot = n * m;

    std::vector<std::string> S(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> S[i];
    }
    --s, --t;

    std::vector<std::vector<int>> dp(1 << tot, std::vector<int>(tot, 0));
    auto get = [&](int i, int j) ->int { return i * m + j; };
    auto check = [&](int x) {
    	int i = x / m, j = x % m;
    	return S[i][j] == '.';
    };

    auto f = [&](int x) {
    	for (int i = 0; i < tot; ++i) {
    		if (x >> i & 1) {
    			if (!check(i)) {
    				return false;
    			}
    		}
    	}
    	return true;
    };

    auto ok = [&](int x, int y) {
    	int x1 = x / m, y1 = x % m;
    	int x2 = y / m, y2 = y % m;
    	if (abs(x1 - x2) + abs(y1 - y2) == 1) {
    		return true;
    	}
    	return false;
    };

    int mask = 0;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if (S[i][j] == '.') {
    			mask |= 1 << get(i, j);
    		}
    	}
    }
    std::vector<int> cnt(1 << tot);
    for (int i = 1; i < 1 << tot; ++i) {
    	if (f(i)) {
    		cnt[i] = 1;
    	}
    }


    dp[1 << get(s, t)][get(s, t)] = 1;

    for (int i = 1; i < 1 << tot; ++i) {
    	for (int j = 0; j < tot; ++j) {
    		if ((i >> j & 1) and cnt[i]) {
    			for (int k = 0; k < tot; ++k) {
    				if (!(i >> k & 1) and check(k) and ok(j, k)) {
    					dp[i ^ (1 << k)][k] |= dp[i][j];
    				}
    			}
    		}	
    	}
    }

    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if (S[i][j] == '.') {
    			if (dp[mask][get(i, j)]) {
    				std::cout << "YES\n";
    				return;
    			}
    		}
    	}
    }
    std::cout << "NO\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
