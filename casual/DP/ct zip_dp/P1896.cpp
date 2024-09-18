#include <bits/stdc++.h>
 
using ll = long long;
using PII = std::pair<int, int>;
const int N = 15;

ll dp[N][110][1 << 9]{0LL};
int cnt[1 << 9]{0};

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> state;
    //预处理出来可行的状态 转移可能在这些状态之间进行
    for (int i = 0; i < 1 << n; ++i) {
    	if (!(i & i >> 1)) {
    		state.emplace_back(i);
    		cnt[i] = __builtin_popcount(i);
    	}
    }
    std::vector<int> head[1 << 9];
    for (auto &a : state)
    	for (auto &b : state) 
    		if (!(a & b) and !((a | b) & (a | b) >> 1))
    			head[a].emplace_back(b);


    dp[0][0][0] = 1;
    for (int i = 1; i <= n + 1; ++i) {
    	for (int j = 0; j <= k; ++j) {
    		for (auto &a : state) {
    			for (auto &b : head[a]) {
    				int c = cnt[a];
    				if (j >= c) 
    					dp[i][j][a] += dp[i - 1][j - c][b];
    			}
            }
        }
    }

    std::cout << dp[n + 1][k][0];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
