#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int mod = 1000000007;

i64 qpow(i64 x, i64 y) {
    i64 ans = 1;
    while (y) {
        if (y & 1) {
            ans = ans * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return ans % mod;
}

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> roots;
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
    	int fa;
    	std::cin >> fa;
    	--fa;
    	if (s[i] == 'R') {
    		roots.push_back(i);
    	} else {
    		adj[fa].push_back(i);
    	}
    }

    // dp[i][0/1/2] 以i为根的子树的权值和mod3是j等待方案数
    // 每棵子树都是单独处理 外加容斥 计算siz即可
    std::vector<int> siz(n);
    std::function<void(int)> dfs = [&](int u) {
    	siz[u] = 1;
    	for (auto v : adj[u]) {
    		dfs(v);
    		siz[u] += siz[v];
    	}
    };
    if (s[0] == 'R') {
        roots.push_back(0);
    }

    for (auto x : roots) {
    	dfs(x);
    }
    std::vector dp(n + 1, std::vector<i64>(3));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 0; j < 3; ++j) {
    		dp[i][(j + 1) % 3] = (dp[i - 1][j] + dp[i][(j + 1) % 3]) % mod;
    		dp[i][(j + 2) % 3] = (dp[i - 1][j] + dp[i][(j + 2) % 3]) % mod;
    	}
    }
    i64 ans = 1;
    for (auto x : roots) {
    	ans = ans * dp[siz[x]][0] % mod;
    }
    int tot = n;
    for (auto x : roots) {
        tot -= siz[x];
    }
    if (tot) {
        ans *= qpow(2, tot);
    }

    std::cout << ans % mod << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
