#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int MOD = 998244353;

void solve() {
    int n, m;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::cin >> m;
    std::vector<int> in(m), out(m);
    std::vector<std::array<i64, 3>> f(m);
    std::vector<std::vector<int>> adj(m), radj(m);
    for (int i = 0; i < m; ++i) {
    	std::cin >> f[i][0];
    	if (f[i][0] == 1) {
    		std::cin >> f[i][1] >> f[i][2];
            f[i][1]--;
    	} else if (f[i][0] == 2) {
    		std::cin >> f[i][1];
    	} else {
    		int k, j;
    		std::cin >> k;
    		while (k--) {
    			std::cin >> j;
                --j;
    			adj[i].push_back(j);
    			radj[j].push_back(i);
    			in[j]++;
    			out[i]++;
    		}
    	}
    }
    int q;
    std::cin >> q;
    std::vector<int> ops(q);
    for (int i = 0; i < q; ++i) {
    	std::cin >> ops[i];
    	ops[i]--;
    }
    std::vector<i64> mul(m, 1);

    std::queue<int> qu;
    for (int i = 0; i < m; ++i) {
    	if (f[i][0] == 2) {
    		mul[i] = f[i][1];
    	}
    	if (!out[i]) {
    		qu.push(i);
    	}
    }
    while (!qu.empty()) {
    	int u = qu.front();
    	qu.pop();

    	for (auto v : radj[u]) {
    		mul[v] = (mul[u] * mul[v]) % MOD;
    		if (--out[v] == 0) {
    			qu.push(v);
    		}
    	}
    }

    std::vector<i64> Fmul(q + 1);
    Fmul[q] = 1;

    std::vector<i64> dp(m);
    for (int i = q - 1; i >= 0; --i) {
    	Fmul[i] = Fmul[i + 1] * mul[ops[i]] % MOD;
    	dp[ops[i]] = (dp[ops[i]] + Fmul[i + 1]) % MOD;
    }

    // qu = std::queue<int>{};
    while (!qu.empty()) qu.pop();
    for (int i = 0; i < m; ++i) {
    	if (!in[i]) {
    		qu.push(i);
    	}
    }
    while (!qu.empty()) {
    	int u = qu.front();
    	qu.pop();

        // 注意这里要倒着遍历边表
        // 因为每个函数执行完乘的倍数只影响在它前面执行的函数
        std::ranges::reverse(adj[u]);
    	for (auto v : adj[u]) {
    		dp[v] = (dp[u] + dp[v]) % MOD;
    		dp[u] = (dp[u] * mul[v]) % MOD;
    		if (--in[v] == 0) {
    			qu.push(v);
    		}
    	}
    }

    for (int i = 0; i < n; ++i) {
    	a[i] = (a[i] * Fmul[0]) % MOD;
    }
    for (int i = 0; i < m; ++i) {
        if (f[i][0] == 1) {
    		a[f[i][1]] = (a[f[i][1]] + dp[i] * f[i][2] % MOD) % MOD;
    	}
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
}	

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
