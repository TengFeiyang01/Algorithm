#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> g[n + 1];
    for (int i = 2, fa; i <= n; ++i) {
    	std::cin >> fa;
    	g[fa].push_back(i);
    }

    std::vector<i64> pre(n + 1), suf(n + 2), dp(n + 1), ans(n + 1), f(n + 1);


    std::function<void(int)> dfs1 = [&](int u) {
    	dp[u] = 1LL;
    	for (auto &v : g[u]) {
    		dfs1(v);
    		dp[u] = (dp[v] + 1) * dp[u] % m;
    	}
    };

    //pre suf 都是针对某个子树计算的
    //eg u下面有a b c 那么以a为根时 答案为 dp[a] * (dp[b] * dp[c]) == suf[a]
    //eg u下面有a b c 那么以b为根时 答案为 dp[b] * (dp[a] * dp[c]) == pre[a] * suf[b]

    dfs1(1);
    std::function<void(int)> dfs2 = [&](int u) {
        int len = g[u].size();
        if (len == 0) return;
    
        pre[0] = 1;
        for (int i = 0; i < len; ++i) pre[i + 1] = pre[i] * (dp[g[u][i]] + 1) % m;
    
        suf[len] = 1;
        for (int i = len - 1; i >= 0; --i) suf[i] = suf[i + 1] * (dp[g[u][i]] + 1) % m;
    
        for (int i = 0; i < len; ++i) {
            int v = g[u][i];
            f[v] = pre[i] * suf[i + 1] % m;
            if (u != 1) f[v] = f[v] * (f[u] + 1) % m;
        }
        for (auto &v : g[u]) {
            ans[v] = (f[v] + 1) * dp[v] % m;
            dfs2(v);
        }
    };
    dfs2(1);
    ans[1] = dp[1];
    for (int i = 1; i <= n; ++i) std::cout << ans[i] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
